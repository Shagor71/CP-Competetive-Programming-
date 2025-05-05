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
int mod;
struct matrix {
	long long mat[2][2];
	matrix friend operator *(const matrix &a, const matrix &b) {
		matrix c;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				c.mat[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					c.mat[i][j] += a.mat[i][k] * b.mat[k][j] % mod;
					c.mat[i][j] %= mod;
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
int f(int p) {
	return (p * (p + 1) / 2) % mod;
}
void solve() {

	int a, b, n, m;
	cin >> a >> b >> n >> m >> mod;

	matrix M{
		{	{a, b},
			{0, 1}
		}
	};

	matrix MM = exp(M, n);

	int res = MM.mat[0][0] * f(m) % mod;
	res += MM.mat[0][1] * m % mod;
	res %= mod;

	cout << res << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}