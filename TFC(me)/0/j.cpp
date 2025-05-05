#include <bits/stdc++.h>
using namespace std;
/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e5 + 5, M = 1e9 + 7;

int dp[N];
vector<int> g[N];
int dfs(int u) {
	int &res = dp[u];
	if (~res) return res;
	res = 0;
	for (auto v : g[u])
		res = max(res, 1 + dfs(v));
	return res;
}
void solve() {

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	memset(dp, -1, sizeof dp);
	int res = 1;
	for (int i = 1; i <= n; ++i)
		res = max(res, dfs(i));

	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}