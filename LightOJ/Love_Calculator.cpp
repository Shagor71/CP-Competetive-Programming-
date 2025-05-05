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

int dp0[35][35], dp1[35][35][70];
string a, b;
int LIS(int i, int j) {
	if (i == a.size() or j == b.size()) return 0;
	int &res = dp0[i][j];
	if (~res) return res;

	if (a[i] == b[j]) return res = LIS(i + 1, j + 1) + 1;
	return res = max(LIS(i + 1, j), LIS(i, j + 1));
}
int len;
int cal(int i, int j, int l) {
	if (i == a.size() and j == b.size()) return l ? 0 : 1;
	if (i == a.size() or j == b.size())
		return (i == a.size() ? cal(i, j + 1, l - 1) : cal(i + 1, j, l - 1));

	int &res = dp1[i][j][l];
	if (~res) return res;
	if (a[i] == b[j]) return res = cal(i + 1, j + 1, l - 1);
	return res = cal(i + 1, j, l - 1) + cal(i, j + 1, l - 1);
}
void solve() {

	cin >> a >> b;

	memset(dp0, -1, sizeof dp0);
	memset(dp1, -1, sizeof dp1);

	len = a.size() + b.size() - LIS(0, 0);
	int unique = cal(0, 0, len);


	cout << "Case " << ++e << ": " << len << ' ' << unique << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}