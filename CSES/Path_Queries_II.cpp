#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
	int size = 1;
	int max_c_size = 0;
	for (int c : adj[v]) {
		if (c != parent[v]) {
			parent[c] = v, depth[c] = depth[v] + 1;
			int c_size = dfs(c, adj);
			size += c_size;
			if (c_size > max_c_size)
				max_c_size = c_size, heavy[v] = c;
		}
	}
	return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
	head[v] = h, pos[v] = cur_pos++;
	if (heavy[v] != -1)
		decompose(heavy[v], h, adj);
	for (int c : adj[v]) {
		if (c != parent[v] && c != heavy[v])
			decompose(c, c, adj);
	}
}

void init(vector<vector<int>> const& adj) {
	int n = adj.size();
	parent = vector<int>(n);
	depth = vector<int>(n);
	heavy = vector<int>(n, -1);
	head = vector<int>(n);
	pos = vector<int>(n);
	cur_pos = 0;
	dfs(0, adj);
	for (int i = 0; i < n; ++i) {
		for (auto x : adj[i]) cout << x << ' ';
		cout << '\n';
	}
	dbg(depth);
	dbg(heavy);
	decompose(0, 0, adj);
}

void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int m = n - 1;
	vector<vector<int>> adj(n * m);
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	init(adj);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int s, x;
			cin >> s >> x;

			continue;
		}
		int a, b;
		cin >> a >> b;
	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}