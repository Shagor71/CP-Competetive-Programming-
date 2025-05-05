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

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int l, r;
	cin >> l >> r;

	int msb = 64 - __builtin_clzll(r);

	int val = 0;
	while (0 <= msb) {
		if (l <= val + (1ll << msb) - 1 and val + (1ll << msb) - 1 <= r) {
			cout << val + (1ll << msb) - 1 << '\n';
			return;
		}
		if ((1ll << msb)&r) val += (1ll << msb);
		msb--;
	}
	cout << l << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}