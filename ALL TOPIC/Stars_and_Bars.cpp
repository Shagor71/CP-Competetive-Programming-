#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mk make_pair
const int N = 1e6 + 7, mod = 1e9 + 7;


int fct[N], ifct[N];

int exp(int a, int p) {
	if (!p) return 1;
	int res = exp(a, p >> 1);
	res = res * res % mod;
	if (p & 1) res = res * a % mod;
	return res;
}
void f() {
	fct[0] = ifct[0] = 1ll;
	for (int i = 1; i < N; ++i) {
		fct[i] = fct[i - 1] * i % mod;
		ifct[i] = exp(fct[i], mod - 2);
	}
	return;
}
int nCr(int n, int r) {
	return fct[n] * ifct[n - r] % mod * ifct[r] % mod;
}
int stars_bars(int nta_jinish, int box) {
	//nta jinishke box gulate koto way te bosano zay;
	return nCr(nta_jinish + box - 1, nta_jinish);
}
void solve() {
	int n, k;
	cin >> n >> k;

	cout << stars_bars(n - k, k) << '\n';
}
signed main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	f();
	int tc; cin >> tc; while (tc--)
		solve();
}