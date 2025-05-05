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

int a[51], dp[51][51][2501], n, avg;

int mgc(int i, int cnt, int sum) {
	if (i == n) {
		if (cnt == 0) return 0;
		return (sum / cnt == avg and sum % cnt == 0);
	}
	int &res = dp[i][cnt][sum];
	if (~res) return res;
	return res = mgc(i + 1, cnt, sum) + mgc(i + 1, cnt + 1, sum + a[i]);
}
void solve() {

	cin >> n >> avg;

	for (int i = 0; i < n; ++i) cin >> a[i];

	memset(dp, -1, sizeof dp);

	cout << mgc(0, 0, 0) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}