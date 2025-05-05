#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mk make_pair
const int N = 1e6 + 7, MX = N, M = 1e12 + 7;
int ee;

int dp[105][105][105];
int n, d;
std::vector<int> a(N);
int cal(int i, int k, int rem) {
	if (k == 0)  return (rem ? -M : 0);
	if (i == n) return -M;
	int &res = dp[i][k][rem];
	if (res != -1) return res;
	return res = max(cal(i + 1, k, rem), a[i] + cal(i + 1, k - 1, (rem + a[i]) % d));
}
void solve() {

	int m;
	cin >> n >> m >> d;

	a.resize(n);
	for (auto &i : a) cin >> i;
	//sort(a.rbegin(), a.rend());

	memset(dp, -1, sizeof dp);

	int res = cal(0, m, 0);
	cout << (res < 0 ? -1 : res) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}