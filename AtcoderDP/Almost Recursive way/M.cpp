#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e5 + 5, INF = 1e9 + 7, M = INF;
strcut st{
	int cost, way;
} dp[N][105];

vector<int> a(N);
int n, k;
void solve() {

	cin >> n >> k;

	a.resize(n);
	for (auto& i : a) cin >> i;
	for (int i = 0; i < n; ++i) {
		vector<int> csum(k, 0ll);
		if (!i) {
			for (int j = 0; j <= a[i]; ++j) {
				dp[i][j] = {k - j, 1};
				csum[j + 1] = csum[j] + dp[i][j];
			}
			continue;
		}
		for (int j = 0; j <= a[i]; ++j) {
			dp[i - 1][]
		}
	}


}
/*
dp[1][0] = 4 dp[2][0] =
dp[1][1] = 3

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}