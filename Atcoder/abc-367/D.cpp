#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 2e5 + 5;

struct st {
	int tmp, rs;
} dp[N];
bool inc[N];
vector<int> g[N];
void dfs(int u, int par) {
	int &cnt = dp[u].rs;

	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
		cnt += max(dp[v].tmp, dp[v].rs);
	}
	//cout << u << ' ' << cnt << '\n';
	dp[u].rs = cnt;
	if (cnt) dp[u].tmp = dp[u].rs + (inc[u] == 0);
	//cout << u << ": " << dp[u].tmp << ' ' << dp[u].rs << '\n';
	return;
}
void solve() {

	int n, m;
	cin >> n >> m;

	int q = n - 1;
	while (q--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		inc[x] = dp[x].rs = 1;
	}

	dfs(1, 0);

	int res = 0;
	for (int i = 1; i <= n; ++i) res = max(res, dp[i].rs);
	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}