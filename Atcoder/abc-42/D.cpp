#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;

int fct[N], ifct[N];

int exp(int a, int p) {
	if (!p) return 1;
	int res = exp(a, p >> 1);
	res = (res * res) % mod;
	if (p & 1) res = (res * a) % mod;
	return res;
}
void FACT() {
	fct[0] = ifct[0] = 1ll;
	for (int i = 1; i < N; ++i) {
		fct[i] = fct[i - 1] * i % mod;
		ifct[i] = exp(fct[i], mod - 2);
		//cout << fct[i] << ' ' << ifct[i] << '\n';
	}
	return;
}
int ncr(int n, int r) {
	//dbg(n, r)
	return fct[n] * ifct[n - r] % mod * ifct[r] % mod;
}
void solve() {

	int H, W, h, w;
	cin >> H >> W >> h >> w;

	int res = ncr(H + W - 2, H - 1);

	for (int r1 = H - h + 1, r2 = h; r1 <= H; r1++, r2--) {
		int tmp = ncr(r1 + w - 2, r1 - 1) * ncr(r2 + W - w - 2, r2 - 1) % mod;
		res = (mod + (res - tmp) % mod) % mod;
	}

	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	FACT();
	solve();
}