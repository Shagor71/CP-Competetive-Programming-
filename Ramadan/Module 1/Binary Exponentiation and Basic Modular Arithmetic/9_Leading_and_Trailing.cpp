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
const int N = 2e5 + 7, MX = N, mod = 1e9 + 7, M = 1e9 + 7;
int e;

int exp(int a, int p, int mod) {
	if (!p) return 1;
	int res = exp(a, p >> 1, mod);
	res = res * res % mod;
	if (p & 1) res = res * a % mod;
	return res;
}
void solve() {

	int a, p;
	cin >> a >> p;

	double frq = p * (log10(a));
	frq = frq - (int)frq;

	int lead = pow(10, frq) * 100;

	cout << setw(3) << setfill('0') << lead << "..." << exp(a, p, 1000) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}