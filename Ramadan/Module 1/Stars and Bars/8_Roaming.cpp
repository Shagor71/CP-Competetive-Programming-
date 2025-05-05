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
	return nCr(nta_jinish + box - 1, nta_jinish);
}
void solve() {

	int n, k;
	cin >> n >> k;

	int res = 0;
	for (int i = 0; i <= min(n, k); ++i) {
		res = (res + nCr(n, i) * stars_bars(i, n - i) % mod) % mod;
		//res = (res + nCr(n, i) * nCr(n - 1, i) % mod) % mod;
	}

	cout << res << '\n';

}
/*
	0 0 0 1 1 1 1 1

	8ta room theke 3ta 1ke 8C3 way te choose korte pari.
	nta room theke kta 1ke nCk way te choose korte pari.

	ei 3ta 1ke 8 - 3 = 5ta  box e stars & bars way te distribute kora zay (3 + 5 - 1)C(3)
	ei kta 1ke n - k ta box e stars & bars way te distribute kora zay (k + n - k - 1)C(k) = (n - 1)C(k)

	for each k:
	( n ) * (n - 1)
    ( k )   (  k  )
*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	f();
	//int tc; cin >> tc; while (tc--)
	solve();
}