#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long int
const int N = 1e6 + 5, mod = 1e9 + 7;

int a[51], dp[51][5000], offset = 2500, n, avg;

int mgc(int i, int sum) {
	if (i == n) {
		return sum == 0;
	}
	int &res = dp[i][sum + offset];
	if (~res) return res;
	return res = mgc(i + 1, sum) + mgc(i + 1, sum + a[i] - avg);
}
void solve() {

	cin >> n >> avg;

	for (int i = 0; i < n; ++i) cin >> a[i];

	memset(dp, -1, sizeof dp);

	cout << mgc(0, 0) - 1 << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}