#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int dp[1005][250], mod = M;
vector<vector<int>> next_mask(250);
bool valid_mask(int x, int m) {
	int prv = -1;
	while (m--) {
		int cur = x % 3;
		if (cur == prv) return 0;
		prv = cur, x /= 3;
	}
	return 1;
}
bool valid(int a, int b, int m) {
	while (m--) {
		if (a % 3 == b % 3) return 0;
		a /= 3, b /= 3;
	}
	return 1;
}
int magic(int row, int mask) {
	if (!row) return 1;
	int &res = dp[row][mask];
	if (~res) return res;
	res = 0;
	for (auto n_mask : next_mask[mask]) {
		res += magic(row - 1, n_mask);
		if (res >= mod) res -= mod;
	}
	return res;
}
int colorTheGrid(int m, int n) {
	int lmt = pow(3, m);
	vector<int> column_mask;
	for (int mask = 1; mask <= lmt; ++mask)
		if (valid_mask(mask, m)) column_mask.push_back(mask);

	for (auto mask1 : column_mask)
		for (auto mask2 : column_mask)
			if (valid(mask1, mask2, m)) next_mask[mask1].push_back(mask2);

	int res = 0;
	memset(dp, -1, sizeof dp);
	for (auto mask : column_mask) {
		res += magic(n - 1, mask);
		if (res >= mod) res -= mod;
	}
	return res;
}
void solve() {
	int m, n;
	cin >> m >> n;

	cout << colorTheGrid(m, n) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}