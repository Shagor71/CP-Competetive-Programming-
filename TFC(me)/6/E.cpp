#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long
const int N = 1e5 + 5, M = 1e9 + 7;

bool dp[105][N], ch[105][N];
std::vector<pair<int, int>> a(N);

void genrt(int i, int j) {
	if (!i) return;
	if (j >= a[i].first and dp[i - 1][j - a[i].first]) {
		genrt(i - 1, j - a[i].first);
		cout << "H";
	}
	else if (j >= a[i].second and dp[i - 1][j - a[i].second]) {
		genrt(i - 1, j - a[i].second);
		cout << "T";
	}
	return;
}
void solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (dp[i][j]) {
				dp[i + 1][j + a[i + 1].first] = dp[i][j];
				dp[i + 1][j + a[i + 1].second] = dp[i][j];
			}
		}
	}
	if (dp[n][k]) {
		cout << "Yes\n";
		genrt(n, k);
		cout << '\n';
	}
	else
		cout << "No\n";
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}