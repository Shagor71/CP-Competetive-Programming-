#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 1e6 + 7, MX = N, M = 1e9 + 7, mod = M;
int e;


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


	int n, m;
	cin >> n >> m;

	int res = 1;
	for (int i = 2; i * i <= m; ++i) {
		if (m % i) continue;
		int cnt = 0;
		while (m % i == 0) cnt++, m /= i;
		res = res * nCr(cnt + n - 1, cnt) % mod;
	}
	if (m != 1) res = res * nCr(1 + n - 1, 1) % mod;

	cout << res << '\n';

}
/*
	3 12

	12 = 2^2 * 3

	|1 1 4|
	|1 2 2|
	|1 4 1|          |1 1 3|
	|2 1 2|  (6 * 3) |1 3 1|
	|2 2 1| = 18     |3 1 1|
	|4 1 1|

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	f();
	//int tc; cin >> tc; while (tc--)
	solve();
}