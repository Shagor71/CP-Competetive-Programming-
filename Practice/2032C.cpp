#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long

const int N = 1e6 + 5;

bool ok(vector<int> &v, int l) {
	for (int i = 0, j = l - 1; j < v.size(); ++i, ++j) if (v[i] + v[i + 1] > v[j]) return 1;
	return 0;
}
void solve() {
	int n; cin >> n;

	vector<int> a(n);
	for (auto &i : a) cin >> i;

	sort(a.begin(), a.end());


	int lo = 3, hi = n, len = 2;
	while (lo <= hi) {
		int m = lo + hi >> 1;
		ok(a, m) ? (len = m, lo = m + 1) : hi = m - 1;
	}

	cout << n - len << '\n';
}
/*


*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}