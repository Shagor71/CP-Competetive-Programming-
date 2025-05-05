#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/

const int N = 1e5 + 7;

int e;

set<int> g[N];
struct st {
	int a, b, c;
};
void solve() {

	int n, m;
	cin >> n >> m;


	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}

	vector<st> res;

	for (int u = 2; u <= n; ++u) {
		while (!g[u].empty()) {
			auto it = g[u].end();
			int v = *(--it);
			if (v == 1) break;
			//dbg(u, v)
			res.push_back({1, u, v});
			// u !- v
			g[u].erase(g[u].find(v));
			g[v].erase(g[v].find(u));
			//dbg(g[u], g[v], g[1])
			// 1 !- u
			if (g[1].find(u) != g[1].end()) {
				g[1].erase(g[1].find(u));
				g[u].erase(g[u].find(1));
			} else // 1 - u
				g[1].insert(u), g[u].insert(1);
			// 1 !- v
			if (g[1].find(v) != g[1].end()) {
				g[1].erase(g[1].find(v));
				g[v].erase(g[v].find(1));
			} else {// 1 - v
				g[1].insert(v), g[v].insert(1);
				//dbg(v)
			}
			//dbg(g[1], g[3], g[2])
		}
	}
	//dbg(g[3].size())
	for (int u = 2; u <= n; ++u)
		if (g[u].empty() and !g[1].empty()) {
			//cout << g[u].size() << ' ';
			auto it = g[1].end();
			int v = *(--it);
			res.push_back({1, u, v});
			// 1 !- v
			g[1].erase(it);
			g[v].erase(g[v].find(1));
			// 1 - u and v - u
			g[1].insert(u);
			g[u].insert(1);
			g[v].insert(u);
			g[u].insert(v);
		}
	//cout << '\n';
	cout << res.size() << '\n';
	for (auto i : res) cout << i.a << ' ' << i.b << ' ' << i.c << '\n';

	for (int i = 1; i <= n; ++i) g[i].clear();
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}