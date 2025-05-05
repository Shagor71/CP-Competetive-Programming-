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
const int N = 2e6 + 7, mod = 1e9 + 7;


int fct[N], ifct[N], e;

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

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());

	int res = 0;
	while (k <= a.size()) {
		res += nCr(a.size() - 1, k - 1) * a.back() % mod;
		res %= mod;
		a.pop_back();
	}

	cout << res << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	f();
	int tc; cin >> tc; while (tc--) {
		cout << "Case #" << ++e << ": ";
		solve();
	}
}