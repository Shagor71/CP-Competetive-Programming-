#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int exp(int a, int p) {
	if (!p) return 1;
	int res = exp(a, p >> 1);
	res = 1ll * res * res % M;
	if (p & 1) res = 1ll * res * a % M;
	return res;
}
void solve() {

	int n, k;
	cin >> n >> k;

	cout << exp(2, n) << '\n';

}
/*

	n = 4 k = 3
	  123
	1 100
	2 010
	3 001
	4 000
	  111

	 or,
	1 010
	2 000
	3 001
	4 100
	  111

	  4*4*4
	  4^3
	  n^k

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}