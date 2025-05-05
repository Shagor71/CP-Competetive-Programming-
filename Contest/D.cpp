#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int dp[1003][1003];
int cal(int i, int j, int n) {
	if (i == n and j == n) return 1;
	if (n < i or n < j) return 0;
	int &res = dp[i][j];
	if (~res) return res;
	res = 0;
	if (i == j)
		return res = cal(i + 1, j + 1, n) + cal(i + 2, j + 2, n) + cal(i + 1, j + 2, n) + cal(i + 2, j + 1, n);
	return res = i > j ? (cal(i, j + 2, n) + cal(i + 1, j + 2, n)) : (cal(i + 2, j, n) + cal(i + 2, j + 1, n));
}

void solve() {

	int n; cin >> n;
	cout << cal(0, 0, n) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}