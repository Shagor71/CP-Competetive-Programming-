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
const int N = 1e6 + 7, MX = N, M = 1e9 + 7;
int e;

double dp[N];
void solve() {

	int n, b;
	cin >> n >> b;

	cout << "Case " << ++e << ": " << (int)(dp[n] / log10(b) + 1) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i < N; ++i) dp[i] = dp[i - 1] + log10(i);
	int tc; cin >> tc; while (tc--)
		solve();
}