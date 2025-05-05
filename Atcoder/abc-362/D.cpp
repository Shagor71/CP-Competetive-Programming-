#include<bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/

const int N = 1e6 + 9, INF = 2e9 + 7;

vector<pair<int, int>> g[N];
int n, res = INF;
vector<int> dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> mx(n + 1, INF), vis(n + 1, 0);
	q.push({0, s});
	mx[s] = 0;
	while (!q.empty()) {
		auto x = q.top(); q.pop();
		int u = x.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto y : g[u]) {
			int v = y.first; int w = y.second;
			int MX = max(mx[u], w);
			if (MX < mx[v]) {
				//if (u == 1 and v == n) res = min(res, w);
				mx[v] = MX;
				q.push({MX, v});
			}
		}
	}
	return mx;
}
struct E {
	int u, v, w;
};

void solve() {
	int m; cin >> n >> m;

	vector<E> edge;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	auto d_1_n = dijkstra(1);
	auto d_n_1 = dijkstra(n);
	//dbg(d_1_n) dbg(d_n_1)

	for (auto i : edge) {
		if (d_1_n[i.u] <= i.w and d_n_1[i.v] <= i.w)
			res = min(res, i.w + max(d_1_n[i.u], d_n_1[i.v]));
		if (d_1_n[i.v] <= i.w and d_n_1[i.u] <= i.w)
			res = min(res, i.w + max(d_1_n[i.v], d_n_1[i.u]));
	}

	cout << res << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}