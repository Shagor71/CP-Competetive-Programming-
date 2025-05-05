#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e3 + 5, INF = 1e9 + 7;

string a, b;
int dp[N][N];

int f(int i, int j) {
	if (i == a.size() or j == b.size()) return 0;
	int &res = dp[i][j];
	if (~res) return res;

	if (a[i] == b[j]) res = f(i + 1, j + 1) + 1;
	else res = max(f(i + 1, j), f(i, j + 1));

	return res;
}
int e;
void solve() {
	int n, m;
	cin >> n >> m >> a >> b;

	memset(dp, -1, sizeof dp);


	cout << "Case " << ++e << ": " << n + m - f(0, 0) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}