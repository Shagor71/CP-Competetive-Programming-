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
const int N = 1e5 + 7, MX = N, Mod = 1e9 + 7, inf = 1e9;
int e;
struct matrix {
	long long mat[4][4];
	matrix friend operator *(const matrix &a, const matrix &b) {
		matrix c;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				c.mat[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					c.mat[i][j] += a.mat[i][k] * b.mat[k][j] % Mod;
					c.mat[i][j] %= Mod;
				}
			}
		}
		return c;
	}
};
matrix exp(matrix M, int p) {
	if (p == 1) return M;
	matrix res = exp(M, p >> 1);
	res = res * res;
	if (p & 1) res = res * M;
	return res;
}
void solve() {

	int n; cin >> n;

	if (n < 3) {
		cout << n + 1 << '\n';
		return;
	}

	matrix M {
		{
			{3, 2, 1, 3},
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 1}
		}
	};

	matrix MM = exp(M, n - 2);
	/*for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) cout << MM.mat[i][j] << " \n"[j == 3];*/

	int res = 0;
	for (int i = 0; i < 4; ++i) {
		res += MM.mat[0][i] * max(1ll, (3 - i)) % Mod;
		res %= Mod;
	}

	cout << res << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}