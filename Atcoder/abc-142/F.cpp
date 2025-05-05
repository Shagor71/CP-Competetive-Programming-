#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

vector<int> adj[N];
int color[N], parent[N], cycle_start, cycle_end, vis[N];

bool dfs(int v) {
	color[v] = 1;
	for (int u : adj[v]) {
		if (color[u] == 0) {
			parent[u] = v;
			if (dfs(u))
				return true;
		} else if (color[u] == 1) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
	}
	color[v] = 2;
	return false;
}
void solve() {

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i  = 1; i <= n; ++i) {
		if (!color[i] and dfs(i)) {
			cout << "0\n";
			return;
		}
	}

	cout << "-1\n";
}
/*
5 6
1 2
2 3
3 4
4 5
5 1
3 5
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}