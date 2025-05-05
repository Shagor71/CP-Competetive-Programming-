#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
#define mk make_pair
const int N = 1e5 + 5, M = 1e9 + 7;

int e;
int exp(int a, int p) {
	if (!p) return 1;
	int res = exp(a, p >> 1);
	res = (res * res) % M;
	if (p & 1) res = (res * a) % M;
	return res;
}
void solve() {

	int n; cin >> n;

	cout << "Case " << ++e << ": " << ((n % M * (n + 1) % M * (n + 2) % M) % M * exp(3, M - 2)) % M << '\n';

}
/*
	2!(2c2 + 3c2 + 4c2 + .... (n+1)c2)
 = 2p2 + 3p2 + 4p2 + ...  + (n+1)p2

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}