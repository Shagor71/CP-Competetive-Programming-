#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

struct st {
	int x, y;
};

void solve() {

	int r, c, n;
	cin >> r >> c >> n;

	int g[r + 1][c + 1], dp[r + 1][c + 1];
	for (int i = 0; i <= r; ++i)
		for (int j = 0; j <= c; ++j) g[i][j] = dp[i][j] = 0;

	while (n--) {
		int x, y;
		cin >> x >> y;
		if (x <= r and y <= c) g[x][y] = 1;
	}
	//cout << r << ' ' << c << '\n';

	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + g[i][j];//, cout << dp[i][j] << " \n"[j == c];
		}

	int i = r, j = c;
	string s = "";
	while (true) {
		//cout << i << ' ' << j << '\n';
		if (!dp[i][j]) {
			while (i > 1) s += 'D', i--;
			while (j > 1) s += 'R', j--;
			break;
		}
		if (i > 1 and dp[i - 1][j] + 1 == dp[i][j] and g[i][j]) s += 'D', i--;
		else if (j > 1 and dp[i][j - 1] + 1 == dp[i][j] and g[i][j]) s += 'R', j--;
		else if (i > 1 and dp[i - 1][j] == dp[i][j]) s += 'D', i--;
		else if (j > 1 and dp[i][j - 1] == dp[i][j]) s += 'R', j--;
		if (i == 1 and j == 1) break;
	}
	reverse(s.begin(), s.end());
	cout << dp[r][c] << ' ' << s << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}