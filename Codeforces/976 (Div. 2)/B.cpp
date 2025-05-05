#include <bits/stdc++.h>
using namespace std;
/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long int
#define mk make_pair
const int N = 2e5 + 5, M = 1e9 + 7, INF = 2e18;

void solve() {

	int k; cin >> k;

	int lo = 1, hi = INF, res = INF;

	while (lo <= hi) {
		int rs = lo + hi >> 1ll;
		int on = rs - (int)sqrtl(rs);
		//cout << rs << ' ' << on  << ' ' << sqrtl(rs) << '\n';
		if (on == k) res = min(res, rs);
		on < k ? lo = rs + 1 : hi = rs - 1;
	}

	cout << (res == INF ? -1 : res) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}