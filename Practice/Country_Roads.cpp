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
bool vis[N];
int dp[N];
void dfs(int u, int to) {
	int tmp = INT_MAX;
	for (auto [v, w] : g[u]) {
		if (vis[v]) continue;
		dfs(v, u);
		tmp = min(tmp, w);
	}
	dp[u] = max(dp[u], tmp);
	return;
}
void solve() {

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	for (int i = 0; i < n; ++i) {
		dfs(i, to);
		cout << dfs(i, to) << '\n';
	}

	cout << min(n, 10) << ' ' << n - min(n, 10) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}