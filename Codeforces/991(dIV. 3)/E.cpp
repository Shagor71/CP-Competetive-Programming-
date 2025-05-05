#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define ll long long
const int N = 1e3 + 7;
int dp[N][N];
int cal(string a, string& b) {
	memset(dp, 0, sizeof dp);
	for (int i = 1; i < a.size(); ++i)
		for (int j = 1; j < b.size(); ++j) {
			dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (a[i] == b[j] and j )});
			//cout << dp[i][j] << " \n"[j == b.size() - 1];
		}

	int i = a.size() - 1, j = b.size() - 1, size = 0;
	string s = "";
	while (i and j) {
		if (a[i] == b[j]) {
			s = a[i] + s;
			b[j] = '?';
			size++;
			i--, j--;
		} else {
			dp[i - 1][j] > dp[i][j - 1] ? i-- : j--;
		}
	}
	dbg(size, b, s)
	return size;
	//cout << s << '\n';
}
void solve() {
	string a, b, c;
	cin >> a >> b >> c;

	string nc = c;
	a = '$' + a, b = '$' + b, c = '#' + c, nc = '#' + nc;
	cout << c.size() - max(cal(a, c) + cal(b, c), cal(b, nc) + cal(a, nc)) - 1 << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}