#include <bits/stdc++.h>
using namespace std;

/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e5 + 5, M = 1e9 + 7;

int e;

void solve() {

	int n, q; cin >> n >> q;

	int l = n + 2, r = n + n + n;
	while (q--) {
		int x;
		cin >> x;

		if (x < l or r < x) cout << "0\n";
		else {
			if (x <= l + n - 1) cout << x - l + 1 << '\n';
			else
				cout << n - (x - (l + n - 1)) << '\n';
		}
	}
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}