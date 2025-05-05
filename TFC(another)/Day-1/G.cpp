#include <bits/stdc++.h>
using namespace std;
/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long int
#define mk make_pair
const int N = 1e5 + 5, M = 998244353;

int dp[N], cnt[N];

int exp(int a, int p) {
	if (!p) return 1ll;
	int res = exp(a, p >> 1) % M;
	res = (res * res) % M;
	if (p & 1) res = (res * a) % M;
	return res;
}
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i, cnt[i]++;

	if (a.front() or cnt[0] > 1) {
		cout << "0\n";
		return;
	}

	dp[0] = cnt[0];
	int mx = *max_element(a.begin(), a.end());

	for (int i = 1; i <= mx; ++i) {
		dp[i] = (dp[i - 1] * exp(cnt[i - 1], cnt[i])) % M;
	}

	cout << dp[mx] << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}