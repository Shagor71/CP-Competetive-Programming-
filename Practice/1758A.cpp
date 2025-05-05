#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 2e5 + 7, M = 998244353;

void solve() {

	int n, m, x;
	cin >> n >> m >> x;

	int gcd = 0, mn = x, y = x;
	for (int i = 1; i < n; ++i) {
		cin >> y;
		gcd = __gcd(gcd, abs(x - y));
		x = y;
		//mn = min(mn, x);
	}

	for (int i = 1; i <= m; ++i) {
		int x; cin >> x;
		cout << __gcd(gcd, y + x) << " \n"[i == m];
	}

}
/*



*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}