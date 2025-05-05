//Problem: https://lightoj.com/problem/civil-and-evil-engineer

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

struct Edge {
	int u, v, weight;
	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};
int n;
int cal(vector<Edge> &edges, vector<int> &tree_id) {
	int cost = 0;
	vector<Edge> update_edges;
	for (Edge e : edges) {
		if (tree_id[e.u] != tree_id[e.v]) {
			cost += e.weight;
			update_edges.push_back(e);
			int old_id = tree_id[e.u], new_id = tree_id[e.v];
			for (int i = 0; i <= n; i++) {
				if (tree_id[i] == old_id)
					tree_id[i] = new_id;
			}
		}
	}
	//for(auto [u, v, w] : update_edges) cout << u << ' ' << v << ' ' << w << '\n';
	return cost;
}
void solve() {

	cin >> n;

	vector<Edge> edges_mn, edges_mx;
	while (1) {
		int u, v, w;
		cin >> u >> v >> w;
		if (!(u + v + w)) break;
		edges_mn.push_back({u, v, w});
	}
	sort(edges_mn.begin(), edges_mn.end());
	edges_mx = edges_mn;
	reverse(edges_mx.begin(), edges_mx.end());

	vector<int> tree_id_mn(n + 1), tree_id_mx;
	for (int i = 0; i <= n; i++) tree_id_mn[i] = i;
	tree_id_mx = tree_id_mn;

	int res = cal(edges_mn, tree_id_mn) + cal(edges_mx, tree_id_mx);

	cout << "Case " << ++e << ": ";
	if (res & 1) cout << res << "/2\n";
	else cout << res / 2 << '\n';

}
/*
test case:
3
1
0 1 10
0 1 20
0 0 0
3
0 1 99
0 2 10
1 2 30
2 3 30
0 0 0
2
0 1 10
0 2 5
0 0 0


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}