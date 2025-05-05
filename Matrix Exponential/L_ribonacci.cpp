#include <bits/stdc++.h>
using namespace std;


#define ll long long
int e;
int mod;

const int NN = 12400000;
int dp[2 * NN], sz;
void cycle() {
	dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 6;
	int i = 4;
	mod = 1000000;
	while (i++) {
		if (dp[i - 3] == 1 and dp[i - 2] == 2 and dp[i - 1] == 3) {
			dp[0] = dp[i - 4];
			return;
		}
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		dp[i] %= mod;
	}
	return;
}
int pw[7];
void solve() {

	long long n;
	int k;
	cin >> n >> k;


	if ((n < 4 or (n < 24 and dp[n - 1] + dp[n - 2] + dp[n - 3] == dp[n]) and dp[n] <= pw[k])) {
		cout << dp[n] << '\n';
		return;
	}

	int res = dp[n % NN] % pw[k];
	cout << setfill('0') << setw(k) << res << '\n';

}
/*

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cycle();
	pw[0] = 1;
	for (int i = 1; i <= 6; ++i) pw[i] = pw[i - 1] * 10;
	int tc; cin >> tc; while (tc--) {
		cout << "Case " << ++e << ": ";
		solve();
	}
}