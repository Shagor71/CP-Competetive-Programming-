#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long int
#define mk make_pair
const int N = 2e5 + 5, M = 1e9 + 7;

vector<int> dpth(N), par(N), in(N), out(N);
vector<int> g[N];
int e;
void dfs(int u, int pr = -1) {
	par[u] = pr;
	in[u] = e++;
	for (auto& v : g[u]) {
		if (v == pr) continue;
		dpth[v] = dpth[u] + 1;
		dfs(v, u);
	}
	out[u] = e++;
	return;
}
bool ancestor(int v, int u) {
	return in[v] <= in[u] and out[u] <= out[v];
}
void solve() {

	int n, q;
	cin >> n >> q;

	int m = n - 1;
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);

	while (q--) {
		int l, u, mx = -1; cin >> l;
		vector<int> a(l);
		for (auto& i : a) {
			cin >> i;
			if (mx < dpth[i]) mx = dpth[i], u = i;
		}

		for (auto& i : a) {
			if (i == u or par[i] == -1) continue;
			i = par[i];
		}
		dbg(u, a);
		bool ok = 1;
		for (auto i : a)
			ok &= ancestor(i, u);
		cout << (ok ? "Yes" : "No") << '\n';
	}
}
/*
 1 2 5 5 6 6 2 3 7 8 8 9 10 10 9 7 3 4 4 1

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//int tc; cin >> tc; while (tc--)
	solve();
}