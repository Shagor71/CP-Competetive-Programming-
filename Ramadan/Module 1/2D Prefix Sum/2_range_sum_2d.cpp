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
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void TwoDSum(vector<vector<ll>>&g, int n, int m) {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];
	return;
}
ll cal(vector<vector<ll>>&g, int x1, int y1, int x2, int y2) {
	return g[x2][y2] - g[x2][y1 - 1] - g[x1 - 1][y2] + g[x1 - 1][y1 - 1];
}
void solve() {

	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<ll>> g(n + 1, vector<ll>(m + 1));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) cin >> g[i][j];

	TwoDSum(g, n, m);

	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << cal(g, x1, y1, x2, y2) << '\n';
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