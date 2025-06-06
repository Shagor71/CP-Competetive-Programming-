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

	int n, mn, mx;
	cin >> n >> mn >> mx;

	vector<int> a(n);
	for (int i = 1; i <= n; ++i) a[i - 1] = i;
	reverse(a.begin(), a.begin() + mn);
	reverse(a.begin(), a.end());

	for (auto i : a) cout << i << ' ';
	cout << '\n';
}
/*

*/
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}