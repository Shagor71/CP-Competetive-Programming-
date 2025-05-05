#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
const int N = 4e6 + 5;

struct st {
	int vg, mn;
} dp[N];

/*int f(int n, int m) {
	if (n == 1) return 1;

	int &res = dp[n];
	if (~res) return res % m;
	//dbg(n);
	res = 0;
	for(int i = 1; i*i <= n; ++i) {

	}
	for (int i = 1; i < n; ++i)  res = (res + f(n - i, m)) % m;
	for (int i = 2; i <= n; ++i) res = (res + f(n / i, m)) % m;
	return res;
}*/
void solve() {

	int n, m;
	cin >> n >> m;

	dp[2] = {1, 1};
	for (int i = 3; i <= n; i++) {
		dp[i].mn = (dp[i - 1].mn << 1 + dp[i - 1].vg) % m;

		dp[i].vg = 0;
	}
	//dbg(f(n, m));
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}