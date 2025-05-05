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

struct E {
	int l, r, q;
};
bool comp(E a, E b) {
	return a.l <= b.l;
}

vector<E> p;
vector<int> ans(N);
int res[3 * N][2];

int combine(int x, int y, int t) {
	return !t ? (x & y) : max(x, y);
}
void build(int node, int l, int r, int t) {
	if (l == r) {
		res[node][t] = (t ? p[l].q : ans[l]);
		//if (!t) cout << node << ' ' << l << ' ' << r << ' ' << res[node][t] << '\n';
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m, t), build(node << 1 | 1, m + 1, r, t);
	res[node][t] = combine(res[node << 1][t], res[node << 1 | 1][t], t);
	//if (!t) cout << node << ' ' << l << ' ' << r << ' ' << res[node][t] << '\n';
}
int query(int node, int l, int r, int fl, int fr, int t) {
	if (fl <= l and r <= fr) return res[node][t];
	if (r < fl or fr < l) return t ? 0 : (1ll << 30) - 1;
	int m = l + r >> 1;
	return combine(query(node << 1, l, m, fl, fr, t), query(node << 1 | 1, m + 1, r, fl, fr, t), t);
}
void solve() {

	int n, q;
	cin >> n >> q;

	p.resize(q);

	int mx = 0;
	for (auto& [l, r, qi] : p) cin >> l >> r >> qi, mx = max(mx, qi);
	sort(p.begin(), p.end(), comp);


	auto bs = [&](int i, int t) {
		int lo = 0, hi = q - 1, rs = t ? -1 : q + 1;
		while (lo <= hi) {
			int m = lo + hi >> 1;
			if (p[m].l <= i and i <= p[m].r) rs = m, (t ? lo = m + 1 : hi = m - 1);
			else
				p[m].l < i ? lo = m + 1 : hi = m - 1;
		}
		return rs;
	};

	build(1, 0, q - 1, 1);
	for (int i = 1; i <= n; ++i) {
		int l = bs(i, 0), r = bs(i, 1);
		if (l > r) ans[i] = 0;
		else ans[i] = query(1, 0, q - 1, l, r, 1);
		//cout << ans[i] << ' ';
	}
	//cout << '\n';

	build(1, 1, n, 0);
	for (auto [l, r, q] : p) {
		if (query(1, 1, n, l, r, 0) != q) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}