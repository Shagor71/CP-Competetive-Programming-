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
	long long mat[2][2];
	matrix friend operator *(const matrix &a, const matrix &b) {
		matrix c;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				c.mat[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				}
			}
		}
		return c;
	}
};
void solve() {

	matrix A, B;

	for (auto ok : {1, 0})
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) cin >> (ok ? A.mat[i][j] : B.mat[i][j]);

	matrix res = A * B;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) cout << res.mat[i][j] << " \n"[j == 1];
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}