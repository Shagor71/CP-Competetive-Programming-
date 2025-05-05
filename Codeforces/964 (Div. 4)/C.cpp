#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

void solve() {

	int q, d, n;
	cin >> q >> d >> n;

	int R = 0;
	bool ok = 0;

	while (q--) {
		int l, r;
		cin >> l >> r;
		ok |= (l - R >= d);
		R = r;
	}
	ok |= (n - R >= d);

	cout << (ok ? "Yes" : "No") << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}