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

int ok(vector<int> &a, int l, int r) {
	int sum = 0, mx = 0;
	for (int i = l; i <= r; ++i) {
		sum = max(0ll, sum + a[i]);
		mx = max(mx, sum);
	}
	return mx;
}
void solve() {

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<int> a(n), pos;
	int ii = -1;
	if (s.front() != '0') pos.push_back(0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (s[i] == '0') {
			if (ii == -1) ii = i;
			pos.push_back(i);
		}
	}
	if (s.back() != '0') pos.push_back(n - 1);

	int Count = count(s.begin(), s.end(), '0');
	if (!Count) {
		if (ok(a, 0, n - 1) != k) {
			cout << "No\n";
			return;
		}
		cout << "Yes\n";
		for (auto i : a) cout << i << ' ';
		cout << '\n';
		return;
	}
	int sum = 0;
	for (int i = 1; i < pos.size(); ++i) {
		int tmp = ok(a, pos[i - 1], pos[i]);
		sum += tmp;
		if (tmp > k) {
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
	int Sum = 0, Pos = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (Pos == -1) {
				Pos = i;
				continue;
			}
			a[i] = -sum;
		}
		Sum += a[i];
	}
	int Left = 0;
	sum = 0;
	for (int i = 0; i <= Pos; ++i) {
		sum = max(sum + a[i], 0ll);
		Left = max(0ll, sum);
	}
	int Right = 0;
	sum = 0;
	for (int i = n - 1; i >= Pos; --i) {
		sum = max(sum + a[i], 0ll);
		Right = max(0ll, sum);
	}
	a[Pos] = k - (Left + Right);
	for (auto i : a) cout << i << ' ';
	cout << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}