#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300 + 7, inf = 1e13;

vector<pair<int, int>> g[N];

struct DSU {
	vector<int> par, rnk, sz;
	int c;
	DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
		for (int i = 1; i <= n; ++i) par[i] = i;
	}
	int find(int i) {
		return (par[i] == i ? i : (par[i] = find(par[i])));
	}
	bool same(int i, int j) {
		return find(i) == find(j);
	}
	int get_size(int i) {
		return sz[find(i)];
	}
	int count() {
		return c;    //connected components
	}
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return -1;
		else --c;
		if (rnk[i] > rnk[j]) swap(i, j);
		par[i] = j;
		sz[j] += sz[i];
		if (rnk[i] == rnk[j]) rnk[j]++;
		return j;
	}
};
int dp[N];
bool vis[N];
int Dijkstra(int at, int to, int n) {
	for (int i = 1; i <= n; ++i) dp[i] = inf, vis[i] = 0;
	dp[at] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({0, at});

	while (!pq.empty()) {
		pair<int, int> u = pq.top();
		pq.pop();
		if (vis[u.second]) continue;
		vis[u.second] = true;
		for (auto it : g[u.second]) {
			int v = it.first, w = it.second;
			if (dp[u.second] + w < dp[v]) {
				dp[v] = dp[u.second] + w;
				pq.push({ -dp[v], v});
			}
		}
	}
	return dp[to];
}
void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	DSU D(n);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w <= k) {
			g[u].push_back({v, w});
			g[v].push_back({u, w});
			D.merge(u, v);
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int at, to;
		cin >> at >> to;

		if (!D.same(at, to)) {
			cout << "-1\n";
			return;
		}
		int tmp = Dijkstra(at, to, n);
		tmp = tmp / k + (tmp % k != 0);
		cout << max(0ll, tmp - 1) << '\n';
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}