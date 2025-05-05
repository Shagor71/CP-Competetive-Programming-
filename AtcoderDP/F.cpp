#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int dp[1001][3001];

void solve() {

	string a, b;
	cin >> a >> b;

	a = '$' + a;
	b = '#' + b;

	for (int i = 1; i < a.size(); ++i)
		for (int j = 1; j < b.size(); ++j) {
			dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (a[i] == b[j])});
			cout << dp[i][j] << " \n"[j == b.size() - 1];
		}

	int i = a.size() - 1, j = b.size() - 1;
	string s = "";
	while (i and j) {
		if (a[i] == b[j]) s = a[i] + s, i--, j--;
		else dp[i - 1][j] > dp[i][j - 1] ? i-- : j--;
	}

	cout << s << '\n';
}
/*
    a b b x b
  a 1 1 1 1 1
  x 1 1 1 2 2
  y 1 1 1 2 2
  b 1 2 2 2 3
  axb
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}