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
const int N = 2e6 + 7, MX = N, mod = 1e9 + 7, M = 1e9 + 7;
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
void solve() {

	int n;
	cin >> n;


	cout << (mod + ((nCr(n + n - 1, n) << 1)  - n) % mod) % mod  << '\n';

}
/*

	f = frequency
	f1 = 1 f1 ta ache
	f2 = 2 f2 ta ache
	f3 = 3 f3 ta ache

	f1 + f2 + f3 + f4 + f5 + .... + fn = n

	n ta stars & (n-1) ta bars
	(n + n -1)
	(  n     )

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	f();
	//int tc; cin >> tc; while (tc--)
	solve();
}