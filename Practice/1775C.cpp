#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 2e5 + 7, M = 998244353;

void solve() {

	int n, k;
	cin >> n >> k;

	if ((n & k) != k) {
		cout << "-1\n";
		return;
	}

	int on_mn = (1ll << 61), off_mx = -1, tn = n;

	for (int i = 60; i >= 0; --i) {
		if ((1ll << i)&k) {
			//cout << (1ll << (i + 1)) - tn << ": ";
			on_mn = min(on_mn, (1ll << (i + 1)) - tn);
			tn ^= (1ll << i);
		}
		else if ((1ll << i)&n) {
			//cout << (1ll << (i + 1)) - tn + 1 << ":: ";
			off_mx = max(off_mx, (1ll << (i + 1)) - tn + 1);
			tn ^= (1ll << i);
		}
		if (on_mn < off_mx) {
			cout << "-1\n";
			return;
		}
	}
	//cout << off_mx << ' ';
	cout << n + max(1ll, off_mx) - 1 << '\n';

}
/*
6: 3::
15



*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}