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

int cnt[N][25];

void solve() {

	int n; cin >> n;

	vector<int> a(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i == 1)
			for (int j = 0; j <= 20; ++j) cnt[0][j] = 0;
		for (int j = 0; j <= 20; j++)
			cnt[i][j] = cnt[i - 1][j] + ((1 << j) & a[i]);
	}

	auto ok = [&](int k) {
		int cmp;
		for (int l = 1, r = k; r <= n; ++l, ++r) {
			int _or = 0;
			for (int j = 0; j <= 20; ++j)
				if (cnt[r][j] - cnt[l - 1][j]) _or |= (1 << j);
			if (l == 1) cmp = _or;
			if (cmp != _or) return 0;
		}
		return 1;
	};

	int lo = 1, hi = n, res = n;
	while (lo <= hi) {
		int m = lo + hi >> 1;
		ok(m) ? (res = m, hi = m - 1) : lo = m + 1l;
	}

	cout << res << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}