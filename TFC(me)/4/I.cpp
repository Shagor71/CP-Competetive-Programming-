#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/#define int long long
const int N = 1e5 + 5;

vector<int> g[N];
int mn[N];

void dfs(int u) {
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);

	}
}
void solve() {
	int n; cin >> n;

	for (int v = 2; v <= n; ++v) {
		int u; cin >> u;
		mn[u] = u, mn[v] = v;
		g[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);

	int q; cin >> q;
	while (q--) {
		int t, u, v;
		cin >> t;
		if (t == 1) {
			cin >> u >> v;
		}
	}
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}