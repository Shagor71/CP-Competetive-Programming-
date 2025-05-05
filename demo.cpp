#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
	int _n, minK, maxK;
	cin >> _n >> minK >> maxK;

	vector<int> nums(_n);
	for (auto& i : nums) cin >> i;

	int mn = 0, mx = 0, n = nums.size();

	if (minK == maxK) {
		long long res = 0;
		for (int i = 0; i < n;) {
			long long cnt = 0, x = nums[i];
			while (i < n and nums[i] == x) cnt++, i++;
			res += cnt * (cnt + 1) / 2;
		}
		cout << res << '\n';
		return;
	}
	vector<int> prf(n + 1);
	prf[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (nums[i - 1] < minK or maxK < nums[i - 1]) {
			mn = mx = i;
			prf[i] = i;
			continue;
		}
		if (nums[i - 1] == minK or nums[i - 1] == maxK) {
			prf[i] = max(mn, mx);
			if (nums[i - 1] == minK) mn = i;
			if (nums[i - 1] == maxK) mx = i;
			continue;
		}
		prf[i] = max({mn, mx, prf[i - 1]});
	}
	mn = mx = n + 1;
	long long l, r, track = n + 1, res = 0;
	for (int i = n; i; --i) {
		if (nums[i - 1] == maxK) {
			l = i - prf[i] - 1;
			r = track - mn;
			cout << l << ' ' << r << ' ' << i << ' ' << prf[i] << ' ' << track << ' ' << mn << '\n';
			if (r > 0) res += l + r + l * r - (l != 0);
			mx = i;
		}
		if (nums[i - 1] == minK) {
			l = i - prf[i] - 1;
			r = track - mx;
			if (r > 0) res += l + r + l * r - (l != 0);
			cout << l << ' ' << r << ' ' << i << ' ' << prf[i] << ' ' << track << ' ' << mx << '\n';
			mn = i;
		}
		if (nums[i - 1] < minK or maxK < nums[i - 1]) track = i;
	}
	cout << res << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}