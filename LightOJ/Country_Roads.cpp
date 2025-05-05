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

#define int long long
#define mk make_pair
const int N = 2e5 + 7, inf = 1e9 + 7, M = 1e9 + 7;
int e;

vector<pair<int, int>> g[N];
int dp[N], vis[N], n;

void reset() {
	for (int i = 0; i < n; ++i) g[i].clear();
	return;
}
void bfs(int at) {
	for (int i = 0; i < n; ++i) dp[i] = inf, vis[i] = 0;
	dp[at] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, at});

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto [v, w] : g[u]) {
			if (max(dp[u],  w) < dp[v]) {
				dp[v] = max(dp[u], w);
				pq.push({dp[v], v});
			}
		}
	}
	return;
}
void solve() {
	int m;
	cin >> n >> m;

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	int to; cin >> to;

	bfs(to);

	cout << "Case " << ++e << ":\n";
	for (int i = 0; i < n; ++i) {
		if (dp[i] != inf) cout << dp[i] << '\n';
		else cout << "Impossible\n";
	}

	reset();
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}