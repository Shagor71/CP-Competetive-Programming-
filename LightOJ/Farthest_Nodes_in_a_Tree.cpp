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
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int dp[N];
std::vector<pair<int, int>> g[N];

void reset(int n) {
	for (int i = 0; i < n; ++i) {
		g[i].clear();
		dp[i] = 0;
	}
}
void dfs(int u, int par = -1) {
	for (auto [v, w] : g[u]) {
		if (v == par) continue;
		dp[v] = dp[u] + w;
		dfs(v, u);
	}
	return;
}
void solve() {

	int n; cin >> n;

	int q = n - 1;
	while (q--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	dfs(0);
	int mx = -1, at;
	for (int i = 0; i < n; ++i) {
		if (mx < dp[i]) at = i, mx = dp[i];
		dp[i] = 0;
	}

	dfs(at);
	int res = -1;
	for (int i = 0; i < n; ++i) res = max(res, dp[i]);

	cout << "Case  " << ++e << ": " << res << '\n';
	reset(n);
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}