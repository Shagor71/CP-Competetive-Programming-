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

int k;
int dp[12][90][90][2];
vector<int> dgt;

void digit(int x) {
	dgt.clear();
	while (x) {
		dgt.push_back(x % 10);
		x /= 10;
	}
	reverse(dgt.begin(), dgt.end());
	return;
}

int cal(int l, int sum_rem, int sum_dgt_rem, int is_sml) {
	if (l == dgt.size()) return !(sum_rem + sum_dgt_rem);
	int &res = dp[l][sum_rem][sum_dgt_rem][is_sml];
	if (~res) return res;
	res = 0;
	int mx_dgt = is_sml ? 9 : dgt[l];
	for (int i = 0; i < mx_dgt; ++i)
		res += cal(l + 1, (sum_rem * 10 + i) % k, (sum_dgt_rem + i) % k, 1);
	return res += cal(l + 1, (sum_rem * 10 + mx_dgt) % k, (sum_dgt_rem + mx_dgt) % k, is_sml);
}

void solve() {

	int l, r;
	cin >> l >> r >> k;

	if (k > 83) {
		cout << "Case " << ++e << ": 0\n";
		return;
	}
	memset(dp, -1, sizeof dp);
	digit(r);
	int res = cal(0, 0, 0, 0);
	memset(dp, -1, sizeof dp);
	digit(l - 1);

	cout << "Case " << ++e << ": " << res - cal(0, 0, 0, 0) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}