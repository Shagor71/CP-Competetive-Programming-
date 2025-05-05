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
const int N = 1e6 + 7, MX = N, M = 1000003;
int e;
int fact[N], ifact[N];

int exp(int a, int p) {
	if (!p) return 1;
	int res = exp(a, p >> 1);
	res = res * res % M;
	if (p & 1) res = res * a % M;
	return res;
}
void fct() {
	fact[0] = ifact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i % M;
		ifact[i] = exp(fact[i], M - 2);
	}
}
int nCr(int n, int r) {
	return fact[n] * ifact[r] % M  * ifact[n - r] % M;
}
void solve() {

	int n, k;
	cin >> n >> k;

	cout << "Case " << ++e << ": " << nCr(n, k) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fct();
	int tc; cin >> tc; while (tc--)
		solve();
}