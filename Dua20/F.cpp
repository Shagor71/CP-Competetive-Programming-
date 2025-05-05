#include <bits/stdc++.h>
using namespace std;
#define int  long long
const int N = 2e5 + 7;

vector<int> g[N];
struct F {
	int sum, cnt;
} dp[N];
int n;
void dfs0(int u, int par) {
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs0(v, u);
		dp[u].sum += dp[v].sum + dp[v].cnt;
		dp[u].cnt += dp[v].cnt;
	}
	dp[u] = {dp[u].sum, dp[u].cnt + 1};
	return;
}
void dfs(int u, int par) {
	for (auto v : g[u]) {
		if (v == par) continue;
		dp[v].sum = dp[u].sum + n - 2 * dp[v].cnt;
		dfs(v, u);
	}
	return;
}
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n;

	int m = n - 1;
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs0(1, 0);
	dfs(1, 0);

	for (int i = 1; i <= n; ++i)
		cout << dp[i].sum << ' ';
}