#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5, mod = 1e9 + 7;

int dp[N][N];
void solve() {
	int n, m;
	cin >> n >> m;
	dp[1][1] = 1ll;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			char c;
			cin >> c;
			if (c == '#') continue;
			dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % mod;
		}

	cout << dp[n][m] << '\n';


}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}