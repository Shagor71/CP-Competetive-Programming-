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
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	int mx = 0;
	for (auto& i : a) cin >> i, mx = max(mx, i);

	auto ok = [&](int mid) {
		int mm = 0;
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			while (i < n and sum + a[i] <= mid) sum += a[i], i++;
			mm++;
			i--;
		}
		return mm <= m;
	};

	int lo = mx, hi = 1e14, res = 0;
	while (lo <= hi) {
		int mid = lo + hi >> 1;
		ok(mid) ? (res = mid, hi = mid - 1) : lo = mid + 1;
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