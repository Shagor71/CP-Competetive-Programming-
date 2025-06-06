//Problem: https://atcoder.jp/contests/dp/tasks/dp_o

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
const int N = 2e5 + 7, MX = N, M = 1e9 + 7, inf = M;
int e;

int g[35][35];
int n, dp[21][1 << 21 + 1];

bool biye_dichi(int bt, int mask) {
	return (1ll << bt) & mask;
}
int cal(int i, ll mask) {
	if (i == n) return 1;
	int &res = dp[i][mask];
	if (~res) return res;
	res = 0;
	for (int w = 1; w <= n; ++w)
		if (!biye_dichi(w - 1, mask) and g[i + 1][w])
			res = (res + cal(i + 1, mask | (1ll << (w - 1)))) % M;

	return res;
}
void solve() {

	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) cin >> g[i][j];

	memset(dp, -1, sizeof dp);

	cout << cal(0, 0ll) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}