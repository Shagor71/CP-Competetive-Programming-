#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 2e5 + 7, M = 1e9 + 7;

int fct[N], ifct[N];

int exp(int a, int p) {
	if (!p) return 1;
	int res = exp(a, p >> 1);
	res = res * res % M;
	if (p & 1) res = res * a % M;
	return res;
}
void fact() {
	fct[0] = ifct[0] = 1;
	for (int i = 1; i < N; ++i) {
		fct[i] = fct[i - 1] * i % M;
		ifct[i] = exp(fct[i], M - 2);
	}
}
int ncr(int n, int r) {
	return fct[n] * ifct[n - r] % M * ifct[r] % M;
}
void solve() {

	int n, k;
	cin >> n >> k;

	k--;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	sort(a.rbegin(), a.rend());

	int p = 0, df = 0;
	for (auto i : a) {
		df += (i > a[k]);
		p += (i == a[k]);
	}

	cout << ncr(p, k - df + 1) << '\n';
}
/*

3 2 1 1
-----
df = 2, p = 2

3
 2 2 2 2 2


1 2 3 4

4C2 = 4*3

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fact();
	int tc; cin >> tc; while (tc--)
		solve();
}