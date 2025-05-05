#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e5 + 5, M = 1e9 + 7;

void solve() {

	/*while (1) {
		int n, m;
		cin >> n >> m;

		while (!n and !m) return;
		char a[n + 1][n + 1], b[4][m + 1][m + 1];

		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> b[0][i][j];

		for (int i = 1; i <= n; ++i) for (int j = n, k = 1; j; j--, k++) b[1][i][k] = b[0][j][i];
		for (int i = 1; i <= n; ++i) for (int j = n, k = 1; j; j--, k++) b[2][i][k] = b[1][j][i];
		for (int i = 1; i <= n; ++i) for (int j = n, k = 1; j; j--, k++) b[3][i][k] = b[2][j][i];

		for (int xx = 0; xx < 4; xx++) {
			int res = 0;
			for (int i = 1; i + m - 1 <= n; ++i) {
				for (int j = 1; j + m - 1 <= n; ++j) {
					bool ok = 1;
					for (int ii = i, k = 1; k <= m; ii++, k++) {
						for (int jj = j, l = 1; l <= m; jj++, l++) {
							if (a[ii][jj] != b[xx][k][l]) {
								ok = 0;
								break;
							}
						}
						if (!ok) break;
					}
					res += ok;
				}
			}
			cout << res << ' ';
		}
		cout << '\n';*/

	//}
	cout << "dkjgf";
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}