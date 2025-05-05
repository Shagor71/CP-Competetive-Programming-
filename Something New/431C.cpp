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

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
ll dp[110][2];
int k, d;
ll cal(int sum, int tkn) {
	if (sum <= 0) return (!sum and tkn);
	ll &res = dp[sum][tkn];
	if (~res) return res;
	res = 0;
	for (int i = 1; i <= k; ++i)
		res = (res + cal(sum - i, tkn or (i >= d))) % M;
	return res;
}
void solve() {

	int n;
	cin >> n >> k >> d;

	memset(dp, -1, sizeof dp);

	cout << cal(n, 0) << '\n';
}
/*
	5 4 2

	2: 5-2 = 3: (1 1 1)(1 2)(2 1)
	    2(1 1 1), 2(1 2), 2(2 1)
	      4         3


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}