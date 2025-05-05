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

void solve() {

	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(n);
	for (auto &i : a) cin >> i;

	while (m--) {
		int l, r;
		cin >> l >> r;
		b[l - 1]++;
		if (r < n) b[r]--;
	}
	for (int i = 1; i < n; ++i) b[i] += b[i - 1];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll res = 0;
	for (int i = 0; i < n; ++i)
		res += 1ll * a[i] * b[i];

	cout << res << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}