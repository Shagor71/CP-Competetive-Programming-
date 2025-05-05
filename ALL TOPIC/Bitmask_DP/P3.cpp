//Problem: https://cses.fi/problemset/task/1690/

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

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7, inf = M;
int e;

std::vector<int> g[35];
int n, dp[21][1 << 21 + 1];

bool zabo(int bt, int mask) {
	return (1ll << bt) & mask;
}
int cal(int u, ll mask) {
	if (u == n) return (1 << u) == mask + 1;

	int &res = dp[u][mask];
	if (~res) return res;
	res = 0;
	//cout << '\n' << u << ": ";
	for (auto v : g[u]) {
		if (!zabo(v - 1, mask)) {
			//cout << v << ' ';
			res = (res + cal(v, mask | (1ll << (v - 1)))) % M;
		}
	}
	return res;
}
void solve() {

	int m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	memset(dp, -1, sizeof dp);

	cout << cal(1, 1) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}