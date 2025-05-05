#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;
int dp[N][2];

void f() {
	for (int i = 1; i < N; ++i) {
		int cnt = 0, t = i;
		while (t) {
			cnt++;
			t /= 3;
		}
		dp[i][0] = dp[i - 1][0] + cnt;
		dp[i][1] = cnt;
	}
}
void solve() {

	int l, r;
	cin >> l >> r;

	cout << dp[r][0] - dp[l - 1][0] + dp[l][1] << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	f();
	int tc; cin >> tc; while (tc--)
		solve();
}