#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
const int N = 1e3 + 5;

void solve() {

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int sum = accumulate(a.begin(), a.end(), 0ll);

	if (sum % 3 or n < 3) {
		cout << "0\n";
		return;
	}
	sum /= 3;
	if (!sum) {
		int tmp = 0, cnt = 0;
		for (auto i : a)
			tmp += i, cnt += tmp == 0;
		cnt -= 2;
		cout << cnt*(cnt + 1) / 2 << '\n';
		return;
	}

	map<int, int> m;
	m[a.front()]++;
	for (int i = 1; i < n; ++i) a[i] += a[i - 1], m[a[i]]++;

	int res = 0;
	for (auto i : a) {
		if (a[i] == sum or a[i] == 2 * sum) {
			m[i]--;
			if (m[i] == sum) res += m[sum + sum];
		}
	}

	cout << res << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}