#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

vector<int> g[N], res;
int dp[N], deg[N], timer, n, root;

void dfs(int u, int par) {
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
		res.push_back(v);
	}
	return;
}
int dp0[N], parents[N];
void dfs0(int u, int par) {
	parents[u] = par;
	dp0[u] = 1;
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs0(v, u);
		dp0[u] += dp0[v];
	}
	return;
}
int centroid() {
	dfs0(1, 0);
	for (int u = 1; u <= n; ++u) {
		int node = 0, mx = 0;
		for (auto v : g[u]) {
			if (v == parents[u]) continue;
			node += dp0[v];
			mx = max(mx, dp0[v]);
		}
		mx = max(mx, n - node - 1);
		if (mx * 2 <= n) return u;
	}
	return 1;
}
void solve() {

	cin >> n;

	int m = n - 1;
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root = centroid();
	dfs(root, 0);

	int j = n >> 1;
	if (!(n & 1)) res.push_back(root);
	//for (auto i : res) cout << i << ' '; cout << '\n';
	for (int i = 0; i < j; i++)
		cout << res[i] << ' ' << res[i + j] << '\n';
}
/*
15
1 2
2 3
2 4
1 6
6 5
6 7
6 10
1 8
8 9
8 11
11 13
8 12
12 14
12 15
*/
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}