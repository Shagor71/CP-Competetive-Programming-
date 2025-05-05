#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e3 + 7, M = 998244353;


void solve() {

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> p(m);
	for (auto& [l, r] : p) cin >> l >> r;

	int q; cin >> q;

	vector<int> a(q + 1);
	for (int i = 1; i <= q; ++i) cin >> a[i];

	auto ok = [&](int pos) {
		vector<int> csum(n + 1, 0);
		for (int i = 1; i <= pos; i++) csum[a[i]] = 1;
		for (int i = 1; i <= n; ++i) csum[i] += csum[i - 1];
		for (auto [l, r] : p) {
			if ((csum[r] - csum[l - 1] << 1) > r - l + 1) return 1;
		}
		return 0;
	};

	int lo = 1, hi = q, res = -1;
	while (lo <= hi) {
		int i = lo + hi >> 1;
		ok(i) ? (res = i, hi = i - 1) : lo = i + 1;
	}

	cout << res << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}