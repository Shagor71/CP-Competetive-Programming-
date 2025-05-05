
vector<int> g[N];
int dp[N], dis[N], vis[N];
void dijkstra(int at, int n) {
	for (int i = 0; i < n; ++i) dp[i] = dis[i] = inf, vis[i] = 0;
	dp[at] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, at});

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto [v, w] : g[u]) {
			//for min value find
			if (dp[v] > max(dp[u],  w)) {
				dp[v] = max(dp[u], w);
				pq.push({dp[v], v});
			}
			//for shortest distance find
			if (dis[v] < dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
	return;
}