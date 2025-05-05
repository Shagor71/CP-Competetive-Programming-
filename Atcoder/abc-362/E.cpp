#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

int dp[85][85][85];
void solve() {

	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i], dp[i][1] = 1;

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j; --j) {
			if (a[j] < a[i]) {
				for (int sz = 2; sz <= i; sz++) {
					dp[i][j][sz] =
				}
			}
		}
	}

}
/*

*/
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}