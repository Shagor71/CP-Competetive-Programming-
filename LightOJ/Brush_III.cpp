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
int w, n, dp[110][110];
vector<int> ds(N);

int cal(int l, int k) {
	if (l == n or !k) return 0;
	int &res = dp[l][k];
	if (~res) return res;
	int lo = l, hi = n - 1, pos = l;
	while (lo <= hi) {
		int m = lo + hi >> 1;
		ds[m] <= ds[l] + w ? (pos = m, lo = m + 1) : hi = m - 1;
	}
	return res = max(cal(l + 1, k), cal(pos + 1, k - 1) + pos - l + 1);
}
void solve() {

	int k;
	cin >> n >> w >> k;

	ds.resize(n);
	int x;
	for (auto& y : ds) cin >> x >> y;
	sort(ds.begin(), ds.end());

	memset(dp, -1, sizeof dp);

	cout << "Case " << ++e << ": " << cal(0, k) << '\n';

}
/*

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}