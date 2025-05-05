#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int dp[N];
vector<int> g[N];

int  dfs(int u) {
	int &ans = dp[u];
	//cout << "u = " << u << " ans = " << ans << "\n";
	if (ans) return ans;
	for (auto v : g[u]) {
		int tmp = 1 + dfs(v);
		//cout << "v = " << v << " tmp = " << tmp << " ans = " << ans << '\n';
		ans = max(ans, tmp);
	}
	return ans;
}
void solve() {
	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) res = max(res, dfs(i));

	cout << res << '\n';
}
/*
	7 -> 6 -> 1 -> 4 <- 3
	     !    !    i
	     8 -> 5 -> 2
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}