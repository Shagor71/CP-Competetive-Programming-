#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 65539;

vector<int> g[N];
int dp[N], timer = 1, pos[N], per[N], n;

void reset() {
	for (int i = 1; i <= n; ++i) {
		dp[i] = 0;
		g[i].clear();
	}
	return;
}
void dfs(int u) {
	for (auto v : g[u])
		dfs(v), dp[u] += dp[v];
	dp[u]++;
	return;
}
bool ok(int pos, int lf, int rt) {
	return (pos + dp[lf] <= n and per[pos + dp[lf]] == rt);
}
void solve() {

	int q;
	cin >> n >> q;

	for (int child = 2; child <= n; ++child) {
		int par;
		cin >> par;
		g[par].push_back(child);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) cin >> per[i], pos[per[i]] = i;

	set<int> odd;
	for (int i = 1; i * 2 <= n; ++i) {
		int ps = pos[i] + 1, lf = g[i][0], rt = g[i][1];
		int a[] = { -1, -1, -1, -1};
		if (per[ps] != lf) a[0] = per[ps];
		if (per[])
			if (ok(pos[i] + 1, g[i][0], g[i][1])) continue;
		odd.insert(i);
	}
	for (auto i : odd) cout << i << ' ';
	/*while (q--) {
		int x, y;
		cin >> x >> y;
		swap(pos[per[x]], pos[per[y]]);
		swap(per[x], per[y]);

	}
	reset();*/
}
/*
	   	 1
	  2     3
	4  5  6   7

   1 2 4 5 3 6 7

   1 2 3 4 5 6 7

       	 1
	  2    35
    53  4  6   7

hash:
1            1
1 2          1 2
1 2 4        1 2 3
1 2 5        1 2 4
1 3          1 5
1 3 6        1 5 6
1 3 7        1 5 7
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}