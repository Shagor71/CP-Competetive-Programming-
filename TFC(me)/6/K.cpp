#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mk make_pair
const int N = 1e3 + 5, M = 998244353;

int exp(int a, int p) {
	if (!p) return 1;
	int res = exp(a, p >> 1);
	res = (res * res) % M;
	if (p & 1) res = (res * a) % M;
	return res;
}
int six;
map<int, int> dp;
int mgc(int n) {
	if (n == 1) return 1;
	int &res = dp[n];
	if (res) return res;

	for (int i = 2; i <= 6; ++i) {
		if (n % i) continue;
		res = (res + mgc(n / i)) % M;
	}
	return res = (res * six) % M;
}
void solve() {

	int n; cin >> n;

	six = exp(5, M - 2);

	cout << mgc(n) << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}