#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
//#define int long long int
#define mk make_pair
const int N = 2e5 + 1, M = 1e7 + 7;

map<int, int> frq[N];
void solve() {

	int n, q;
	cin >> n >> q;

	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		for (auto j : {1, 2, 3}) frq[i][j] = frq[i - 1][j] + (j == x);
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		int sz = r - l + 1;
		if (sz & 1) {
			cout << "No\n";
			continue;
		}
		vector<int> v(3);
		for (auto i : {1, 2, 3}) v[i - 1] = frq[r][i] - frq[l - 1][i];
		sort(v.begin(), v.end());

		cout << ( ? "Yes" : "No") << '\n';
	}
}
/*
	1 1 1 2 3 2

	1

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc; while (tc--)
		solve();
}