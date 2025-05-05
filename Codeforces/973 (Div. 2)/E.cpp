#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long int
#define mk make_pair
const int N = 2e5 + 1, INF = 1e14 + 7;

void solve() {

	int n, d, q;
	cin >> n >> d >> q;

	vector<int> dp(n + 2, 0), csum(n + 1, 0);
	while (q--) {
		int l, r; cin >> l >> r;
		dp[l]++;
		dp[r + 1]--;
	}

	for (int i = 1; i <= n; ++i) {
		dp[i] += dp[i - 1];
		csum[i] = csum[i - 1] + dp[i];
	}
	dbg(dp);

	int res1, mx = -1, mn = csum[n] + 100, res2;
	for (int i = 0; i + d <= n; ++i) {
		int tmp = csum[i + d] - csum[i];
		if (tmp > mx) res1 = i + 1, mx = tmp;
		if (tmp < mn) res2 = i + 1, mn = tmp;
	}

	cout << res1 << ' ' << res2 << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc; while (tc--)
		solve();
}