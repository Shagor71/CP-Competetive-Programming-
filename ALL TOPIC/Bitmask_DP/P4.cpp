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

vector<pair<int, int>> g[12];
int n, dp[12][1 << 12 + 1];

bool zabo(int bt, int mask) {
	return (1ll << bt) & mask;
}
int cal(int u, int mask) {
	int &res = dp[u][mask];
	if (~res) return res;
	res = inf;
	for (auto [v, w] : g[u])
		if (!zabo(v - 1, mask))
			res = min(res, w + cal(v, mask | (1 << (v - 1))));

	return res;
}
void solve() {

	cin >> n;
	n++;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			int w;
			cin >> w;
			g[i].push_back({j, w});
		}
	}

	memset(dp, -1, sizeof dp);

	cout << cal(0, 0ll) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}