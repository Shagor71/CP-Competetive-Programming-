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
vector<int> g[N];
int dp[2], vis[N];

void dfs(int u, int who) {
	dp[who]++;
	vis[u] = 1;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v, 1 - who);
	}
}
void solve() {

	int n; cin >> n;

	set<int> se;
	int q = n;
	while (q--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		se.insert(u), se.insert(v);
	}
	int res = 0;
	for (auto i : se) {
		dp[0] = dp[1] = 0;
		if (!vis[i]) dfs(i, 0);
		res += max(dp[0], dp[1]);
	}

	cout << "Case " << ++e << ": " << res << '\n';

	for (auto i : se) g[i].clear(), vis[i] = 0;

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}