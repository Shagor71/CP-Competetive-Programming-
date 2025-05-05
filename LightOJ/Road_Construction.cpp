#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

//#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

struct Edge {
	string u, v;
	int weight;
	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};
int n;
map<string, int> tree_id;
int cal(vector<Edge> &edges, set<string> &se) {
	int cost = 0;
	vector<Edge> update_edges;
	for (Edge e : edges) {
		if (tree_id[e.u] != tree_id[e.v]) {
			cost += e.weight;
			//update_edges.push_back(e);
			int old_id = tree_id[e.u], new_id = tree_id[e.v];
			for (auto i : se) {
				if (tree_id[i] == old_id)
					tree_id[i] = new_id;
			}
		}
	}
	//for(auto [u, v, w] : update_edges) cout << u << ' ' << v << ' ' << w << '\n';
	return cost;
}
map<string, vector<string>> g;
map<string, bool> vis;
int cnt;
void dfs(string u) {
	cnt++;
	vis[u] = 1;
	for (auto v : g[u])
		if (!vis[v]) dfs(v);
	return;
}
void solve() {

	cin >> n;

	int m = n;
	vector<Edge> edge;
	set<string> se;
	tree_id.clear();
	g.clear(), vis.clear();
	while (m--) {
		string u, v;
		int w;
		cin >> u >> v >> w;
		g[u].push_back(v);
		g[v].push_back(u);
		se.insert(u), se.insert(v);
		edge.push_back({u, v, w});
	}
	sort(edge.begin(), edge.end());

	int j = 0;
	for (auto i : se) tree_id[i] = j++;

	cnt = 0;
	dfs(*se.begin());

	cout << "Case " << ++e << ": ";
	if (cnt != se.size()) cout << "Impossible\n";
	else cout << cal(edge, se) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}