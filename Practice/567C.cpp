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
const int N = 1e6 + 5, M = 1e9 + 7;


map<pair<int, int>, int> dp;
set<int> se;

void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i], se.insert(a[i]);

	for (int i = 1; i <= n; ++i) {
		int x = a[i];

		if (x % k) {
			dp[mk(x, 1)]++;
			continue;
		}
		dp[mk(x, 3)] += dp[mk(x / k, 2)];
		dp[mk(x, 2)] += dp[mk(x / k, 1)];
		dp[mk(x, 1)]++;
		//cout << dp[mk(x, 3)] << ' ' << dp[mk(x, 2)] << ' ' << dp[mk(x, 1)] << '\n';
	}

	int res = 0;
	for (auto i : se) res += dp[mk(i, 3)];

	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}