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
int dp[65][65];
string s;
int cal(int i, int j) {
	if (j < i) return 0;
	if (i == j) return 1;
	int &res = dp[i][j];
	if (~res) return res;
	if (s[i] == s[j]) return res = 1 + cal(i + 1, j) + cal(i, j - 1);
	return res = cal(i + 1, j) + cal(i, j - 1) - cal(i + 1, j - 1);
}
void solve() {

	cin >> s;


	memset(dp, -1, sizeof dp);

	cout << "Case " << ++e << ": " << cal(0, s.size() - 1) << '\n';


}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}