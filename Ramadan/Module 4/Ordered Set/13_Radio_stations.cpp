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

	int n, kk;
	cin >> n >> kk;

	vector<pair<int, int>> a[10020];
	set<int> se;
	for (int i = 0; i < n; ++i) {
		int x, r, f;
		cin >> x >> r >> f;
		a[f].push_back({r, x});
		se.insert(f);
	}
	/*for (auto f : se) {
		sort(a[f].begin(), a[f].end());
		for (auto [r, x] : a[f]) cout << f << ' ' << r << ' ' << x << '\n';
	}*/

	vector<array<int, 3>> rng[10020];
	//int res = 0;
	for (auto i : se) {
		for (int j = 0; j < a[i].size(); ++j) {
			int lf = a[i][j].second - a[i][j].first;
			int rt = a[i][j].second + a[i][j].first;
			for (int k = i; k <= i + kk; ++k) {
				int lo = i == k ? j + 1 : 0, hi = a[k].size() - 1, L = -1;
				while (lo <= hi) {
					int m = lo + hi >> 1;
					a[i][j].first <= a[k][m].first ? (L = m, hi = m - 1) : lo = m + 1;
				}
				if (~L) rng[k].push_back({L, lf, rt});
				//res += (lf <= query.a[k].second(L, R) <= rt);
			}
			for (int k = i - 1; k >= max(0, i - kk); --k) {
				int lo = 0, hi = a[k].size() - 1, L = -1;
				while (lo <= hi) {
					int m = lo + hi >> 1;
					a[i][j].first < a[k][m].first ? (L = m, hi = m - 1) : lo = m + 1;
				}
				if (~L) rng[k].push_back({L, lf, rt});
			}
		}
	}
	/*cout << '\n';
	for (auto i : se) {
		cout << i << ":\n";
		for (auto j : rng[i]) cout << j[0] << ' ' << j[1] << ' ' << j[2] << '\n';
	}*/

	ll res = 0;
	for (auto i : se) {
		sort(rng[i].begin(), rng[i].end());
		o_set<int> s;
		for (int j = a[i].size() - 1; j >= 0; --j) {
			s.insert(a[i][j].second);
			while (!rng[i].empty() and rng[i].back()[0] == j) {
				res += 1ll * (s.order_of_key(rng[i].back()[2] + 1) - s.order_of_key(rng[i].back()[1]));
				rng[i].pop_back();
			}
		}
	}


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