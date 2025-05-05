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

ll cal(vector<int>& a, int l, int r) {
	if (l > r) return 0;
	int mn = *min_element(a.begin() + l, a.begin() + r + 1), m;
	for (int i = l; i <= r; ++i) {
		a[i] -= mn;
		if (!a[i]) m = i;
	}
	return min(cal(a, l, m - 1) + cal(a, m + 1, r) + mn, 1ll * (r - l + 1));
}
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	cout << cal(a, 0, n - 1) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}