#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
int nCr(int n, int k) {
	// (n)(n) * (n-1)(n-1) * (n-2)(n-2)... (n-k+1)(n-k+1)
	int fct = 1, res = 1;
	for (int i = 1; i <= k; ++i) fct *= i;
	for (int i = n; i >= n - k + 1; i--) {
		res *= i * i;
		int gcd = __gcd(res, fct);
		res /= gcd, fct /= gcd;
	}
	return res;
}
void solve() {

	int n, k;
	cin >> n >> k;

	cout << "Case " << ++e << ": " << (n >= k ? nCr(n, k) : 0) << '\n';

}
/*
eseddd
*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}