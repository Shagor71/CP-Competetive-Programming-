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
const int N = 2e5 + 7, MX = N, M = 1e9 + 7, inf = 1e9 + 7;
int e;

int n;

vector<pair<int, int>> g[N];
int dp[N], dis[N], vis[N];
void reset() {
	for (int i = 1; i <= n; ++i) g[i].clear();
}
int dijkstra(int at) {
	for (int i = 1; i <= n; ++i) dis[i] = inf, vis[i] = 0;
	dis[at] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, at});

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto [v, w] : g[u]) {
			//for shortest distance find
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
	return dis[n];
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

	int res = dijkstra(1);
	reset();

	cout << "Case " << ++e << ": ";
	if (res != inf) {
		cout << res << '\n';
		return;
	}

	cout << "Impossible\n";

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}