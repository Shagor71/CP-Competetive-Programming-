#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 2e5 + 7, M = 998244353;

vector<int> g[N];
int cycle[N], ele, vis[N];

void dfs0(int u) {
	vis[u] = 1;
	for (auto v : g[u]) if (!vis[v]) dfs0(v);
	return;
}
int dfs(int u, int par = -1) {
	cycle[u] = 1;
	for (auto v : g[u]) {
		if (par == v) continue;
		if (!cycle[v] && dfs(v, u)) return 1;
		if (cycle[v] == 1) return 1;
	}
	cycle[u] = 2;
	return 0;
}
void solve() {

	int n; cin >> n;

	for (int u = 1; u <= n; ++u) {
		int v; cin >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int mn = 0, mx = 0, ext = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		mx++;
		dfs0(i);
		dfs(i) ? mn++ : ext = 1;
	}
	cout << mn + ext << ' ' << mx << '\n';

	for (int i = 1; i <= n; ++i) g[i].clear(), cycle[i] = vis[i] = 0;
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}