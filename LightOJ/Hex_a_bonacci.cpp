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
const int N = 2e5 + 7, MX = N, M = 1e7 + 7;
int e;
ll dp[N];

ll cal(int n) {
	if (n < 0) return 0;
	ll &res = dp[n];
	if (~res) return res;
	res = 0;
	for (int i = 1; i <= 6; ++i) res = (res + cal(n - i)) % M;
	return res;
}
void solve() {

	memset(dp, -1, sizeof dp);
	for (int i =  0, x; i < 6; ++i) cin >> x, dp[i] = x % M;

	int n; cin >> n;


	cout << "Case " << ++e << ": " << cal(n) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}