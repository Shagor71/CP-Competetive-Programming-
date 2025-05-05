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
#define mk make_pair
const int N = 5e3 + 5, M = 1e9 + 7;

int n, k;
int fct[N], ifct[N];

struct st {
	int R, D;
};

int exp(int a, int p) {
	if (!p) return 1;
	int res = exp(a, p >> 1);
	res = (res * res) % M;
	if (p & 1) res = (res * a) % M;
	return res;
}
void FACT() {
	fct[0] = ifct[0] = 1ll;
	for (int i = 1; i < N; ++i) {
		fct[i] = (fct[i - 1] * i) % M;
		ifct[i] = exp(fct[i], M - 2);
	}
}
int ncr(int n, int r) {
	return fct[n] * ifct[n - r] % M * ifct[r] % M;
}
int stars_bars(int n, int r) {
	return ncr(n + r - 1, n);
}
void solve() {

	while (true) {
		cin >> n >> k;

		if (!n and !k) return;

		st box;
		k & 1 ? box = {k + 1 >> 1, k + 1 >> 1} : box = {k >> 1, (k >> 1) + 1};
		st sum = {n - 1 - box.R, n - 1 - box.D};
		//cout << box.R << ' ' << box.D << ' ' << sum.R << ' ' << sum.D << '\n';

		cout << (2 * stars_bars(sum.R, box.R) * stars_bars(sum.D, box.D)) % M << '\n';
	}
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