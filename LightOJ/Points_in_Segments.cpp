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
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());


	auto bs = [&](int x) {
		int lo = 0, hi = n - 1, res = 0;
		while (lo <= hi) {
			int m = lo + hi >> 1;
			a[m] <= x ? (res = m + 1, lo = m + 1) : hi = m - 1;
		}
		return res;
	};

	cout << "Case " << ++e << ":\n";
	while (q--) {
		int l, r;
		cin >> l >> r;

		cout << bs(r) - bs(l - 1) << '\n';
	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}