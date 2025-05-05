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
const int N = 2e1 + 7, MX = N, M = 1e9 + 7, inf = M;
int e;

int dp[N][3];
void solve() {

	int n; cin >> n;

	int a[n + 1][3];
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 3; ++j) cin >> a[i][j];

	memset(dp, -1, sizeof dp);

	function<int(int, int)> cal = [&](int i, int j)->int {
		if (!i) return 0;
		int &res = dp[i][j];
		if (~res) return res;
		res = inf;
		for (int k = 0; k < 3; ++k)
			if (j != k)
				res = min(res, a[i][j] + cal(i - 1, k));
		return res;
	};

	cout << "Case " << ++e << ": " << min({cal(n, 0), cal(n, 1), cal(n, 2)}) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}