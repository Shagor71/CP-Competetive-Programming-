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

vector<int> g[N];
bool vis[N];
void dfs(int u) {
	vis[u] = 1;
	for (auto v : g[u]) {
		if (!vis[v]) dfs(v);
	}
}
void solve() {

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int res = 0;
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) res++, dfs(i);

	cout << res - 1 << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}