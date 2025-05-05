#include <bits/stdc++.h>
using namespace std;


#define int long long int
const int N = 3e5 + 7;

int e;

int dp[N][2];
void solve() {

	int n; cin >> n;

	dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;
	int J = 0;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		//without keeping gap
		dp[i][0] = dp[i - 1][0] + (dp[i - 1][0] < x) - (dp[i - 1][0] > x);
		//keeping gap
		if (i > 1) {
			int tmp = J;
			tmp += (tmp < x) - (tmp > x);
			dp[i][1] = max(tmp, dp[i - 1][1] + (dp[i - 1][1] < x) - (dp[i - 1][1] > x));
		}
		J = max(J, dp[i - 1][0]);
	}

	cout << max(J, dp[n][1]) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--) {
		solve();
	}
}