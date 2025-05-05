//Problem: https://toph.co/p/fun-with-functions

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
vector<vector<int>> multiply(vector<vector<int>>& M1, vector<vector<int>>&M2) {
	vector<vector<int>> res = {{0, 0}, {0, 0}};
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) {
			res[i][j] = 0;
			for (int k = 0; k < 2; ++k)
				res[i][j] = (res[i][j] + (M1[i][k] * M2[k][j] % mod)) % mod;
		}
	return res;
}
vector<vector<int>> exp(vector<vector<int>>& M, int p) {
	if (p == 1) return M;
	vector<vector<int>> res = exp(M, p >> 1);
	res = multiply(res, res);
	if (p & 1) res = multiply(res, M);
	return res;
}
int f(int p) {
	return (p * (p + 1) / 2) % mod;
}
void solve() {

	int a, b, n, m;
	cin >> a >> b >> n >> m >> mod;

	vector<vector<int>> mat = {{a, b}, {0, 1}};
	vector<vector<int>> matrix = exp(mat, n);

	int res = matrix[0][0] * f(m) % mod;
	res += matrix[0][1] * m % mod;

	cout << res % mod << '\n';

	//for (auto i : res)
	//for (auto j : i) cout << j << ' ';


}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}