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
//cout << "Case " << ++e << ": ";
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n; cin >> n;

	int res = 0;
	while (n--) {
		int x; cin >> x;
		if (x > 0) res += x;
	}

	cout << "Case " << ++e << ": " << res << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}