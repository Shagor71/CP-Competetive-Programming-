#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
#define mk make_pair
const int N = 1e6 + 5, M = 1e9 + 7;

set<int> g[N];
int level[N], cnt[N], parn[N];

void reset(int n) {
	for (int i = 1; i <= n; ++i) {
		level[i] = cnt[i] = parn[i] = 0;
		g[i].clear();
	}
}
void dfs(int u, int par) {
	parn[u] = par;
	for (auto v : g[u]) {
		if (v == par) continue;
		level[v] = level[u] + 1;
		dfs(v, u);
	}
	return;
}
void dfs0(int u, int par) {
	cout << u << ' ';
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs0(v, u);
	}
	return;
}
void solve() {

	int n; cin >> n;

	int q = n - 1;
	while (q--) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	level[1] = 1;
	dfs(1, -1);

	set <pair<int, int>> se;
	for (int i = 1; i <= n; ++i) {
		cnt[level[i]]++;
		if (i != 1 and g[i].size() == 1) se.insert({level[i], i});
	}

	int res = 1, sum = 1;
	//dbg(se);
	for (int i = 2; i <= n; ++i) {
		res = max(res, sum + cnt[i]);
		sum += cnt[i];
		while (!se.empty() and g[se.begin()->second].size() == 1 and se.begin()->first <= i) {
			int pr = se.begin()->second;
			while (pr != 1 and g[pr].size() == 1) {
				g[parn[pr]].erase(g[parn[pr]].find(pr));
				sum--;
				pr = parn[pr];
			}
			se.erase(se.begin());
		}
		//dfs0(1, 0); cout << '\n';
	}

	cout << n - res << '\n';
	reset(n);
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}