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
	int mx1, mx2, f1, f2;
};

int cal(vector<pair<int, int>> &p, int x) {
	int cnt = 0;
	for (auto [mx, f] : p) cnt += (mx == x ? f : 0);
	return cnt;
}
E combine(E x, E y) {
	vector<pair<int, int>> p = {{x.mx1, x.f1}, {x.mx2, x.f2}, {y.mx1, y.f1}, {y.mx2, y.f2}};
	sort(p.rbegin(), p.rend());
	int mx;
	for (auto [x, f] : p) {
		if (x != p.front().first) {
			mx = x;
			break;
		}
	}
	return {p.front().first, mx, cal(p, p[0].first), cal(p, mx)};
}
struct SegmentTree {
	E t[3 * MX];
	int n;

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id] = {a[tl - 1], 0, 1, 0}; // Index 1
			return;
		}
		int tm = tl + tr >> 1;
		build(a, id << 1, tl, tm), build(a, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1]);
	}

	void build(vector<int> &a) {
		n = a.size();
		build(a, 1, 1, n); // Index 1
	}

	E query(int l, int r, int id, int tl, int tr) {
		if (tr < l or r < tl) return {0, 0, 0, 0};
		if (l <= tl and tr <= r) return t[id];
		int tm = tl + tr >> 1;
		return combine(query(l, r, id << 1, tl, tm), query(l, r, id << 1 | 1, tm + 1, tr));
	}

	E query(int l, int r) {
		assert(n > 0);
		if (l > r) return {0, 0, 0, 0};
		return query(l, r, 1, 1, n); // Index 1
	}

	void update(int pos, int val, int id, int tl, int tr) { // O(logn)
		if (tl == tr) {
			t[id] = {val, 0, 1, 0};
			return;
		}
		int tm = tl + tr >> 1;
		pos <= tm ? update(pos, val, id << 1, tl, tm) : update(pos, val, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1]);
	}

	void update(int pos, int val) {
		assert(n > 0);
		update(pos, val, 1, 1, n); // Index 1
	}
} seg;
void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	seg.build(a);

	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 2) {
			cout << seg.query(l, r).f2 << '\n';
			continue;
		}
		seg.update(l, r);
	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}