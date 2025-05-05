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

	int n, w;
	cin >> n >> w;

	vector<int> x(n);
	int y;
	for (auto& i : x) cin >> y >> i;
	sort(x.begin(), x.end());

	int i = 0, res = 0;
	while (i < n) {
		int lo = i, hi = n - 1, pos = i;
		while (lo <= hi) {
			int m = lo + hi >> 1;
			x[m] - x[i] <= w ? (pos = m, lo = m + 1) : hi = m - 1;
		}
		i = pos + 1;;
		res++;
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