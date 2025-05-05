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

int vis[N];
vector<pair<int, int>> g[N];

int res;
void dfs(int u, int par = -1) {
	vis[u] = 1;
	for (auto [v, w] : g[u]) {
		if (v == par) continue;
		if (!vis[v] or v == 1)
			res += w, dfs(v, u);
	}
	return;
}
void reset(int n) {
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		vis[i] = 0;
	}
}
void solve() {

	int n; cin >> n;

	int m = n, sum = 0;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, 0});
		sum += w;
	}

	res = 0;
	dfs(1, 1);

	cout << "Case " << ++e << ": " << min(sum - res, res) << '\n';

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