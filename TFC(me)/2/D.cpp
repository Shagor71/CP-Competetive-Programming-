#include <bits/stdc++.h>
using namespace std;

/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e3 + 5, M = 1e5 + 7;

int e;
int ds[N];

set<int> se;
vector<int> g[N];
void dfs(int u, int par) {
	//cout << u << ' ';
	for (auto v : g[u]) {
		if (v == par and !ds[v]) continue;
		if (ds[v] > ds[u] + 1) {
			ds[v] = ds[u] + 1;
			dfs(v, u);
		}
	}
	return;
}
void solve() {

	int n, h, l;
	cin >> n >> h >> l;

	for (int i = 0; i < n; ++i) ds[i] = M;

	while (h--) {
		int x; cin >> x;
		se.insert(x);
		ds[x] = 0;
	}

	while (l--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (auto i : se) dfs(i, -1);

	int res, mx = 0;
	for (int i = n - 1; i > -1; i--) if (mx <= ds[i]) mx = ds[i], res = i;
	//cout << '\n';
	//for (int i = 0; i < n; ++i) cout << ds[i] << " \n"[i == n - 1];
	cout << res << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}