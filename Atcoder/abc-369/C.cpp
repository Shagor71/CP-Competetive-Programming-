#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

int dp[N];
void solve() {

	int n, x;
	cin >> n >> x;
	dp[1] = 1;

	int df = 0, res = 1;
	for (int i = 2; i <= n; ++i) {
		int y;
		cin >> y;
		if (df == y - x) dp[i] = dp[i - 1] + 1;
		else dp[i] = 2;
		res += dp[i];
		df = y - x;
		x = y;
	}

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