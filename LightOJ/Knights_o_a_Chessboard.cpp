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

//#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n, m;
	cin >> n >> m;

	cout << "Case " << ++e << ": ";

	if (n < m) swap(n, m);

	if (m == 1) {
		cout << n << '\n';
		return;
	}
	if (m == 2) {
		cout << max({4, n, 2 * (2 * (int)(n / 4) + min(2, n % 4))}) << '\n';
		return;
	}
	cout << (int)((n + 1) / 2) * (int)((m + 1) / 2) + (int)(n / 2) * (int)(m / 2) << '\n';


}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}