#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7, INF = 1e9 + 37;

struct E {
	int mn, mx;
};
E combine(E x, E y) {
	return {min(x.mn, y.mn), max(x.mx, y.mx)};
}
//int t[3 * N];
struct SegmentTree {
	E t[3 * N];
	int n;

	void clear(int n) {
		for (int i = 1; i < 3 * n; i++) {
			t[i] = {INF, -1}; // Index 1
		}
		this->n = n;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id] = {a[tl - 1], a[tl - 1]}; // Index 1
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

	int query(int l, int r, int id, int tl, int tr, int ok) {
		if (tr < l or r < tl) return ok ? 0ll : INF;
		if (l <= tl and tr <= r) return ok ? t[id].mx : t[id].mn;
		int tm = tl + tr >> 1;
		if (ok) return max(query(l, r, id << 1, tl, tm, ok), query(l, r, id << 1 | 1, tm + 1, tr, ok));
		return min(query(l, r, id << 1, tl, tm, ok), query(l, r, id << 1 | 1, tm + 1, tr, ok));
	}

	int query(int l, int r, int ok) {
		assert(n > 0);
		if (l > r) return 0;
		//dbg(l, r)
		return query(l, r, 1, 1, n, ok); // Index 1
	}
} seg;
int n;
int cal(int posmn, int mx, int mn) {
	E l = {INF, -1};
	if (posmn) l = {seg.query(1, posmn, 0), seg.query(1, posmn, 1)};
	int res = INF;
	//dbg(posmn);
	for (int i = posmn + 1; i < n - 1; ++i) {
		E m = {seg.query(posmn + 1, i + 1, 0), seg.query(posmn + 1, i + 1, 1)};
		E r = {seg.query(i + 2, n, 0), seg.query(i + 2, n, 1)};
		E nd = combine(l, r);
		cout << posmn + 1 << ' ' << i + 1 << ' ' << i + 2 << ' ' << n << ' ' << m.mn << ' ' << m.mx << ' ' << r.mn << ' ' << r.mx << ' ';
		int aa = max(0ll, nd.mn - m.mn);
		int bb = max(0ll, nd.mx - m.mx);
		cout << aa << ' ' << bb << '\n';
		res = min({res, mx - (mn + min(aa, bb))});
	}
	E r = {INF, -1};
	if (posmn != n - 1) r = {seg.query(posmn + 2, n, 0), seg.query(posmn + 2, n, 1)};

	for (int i = posmn; i > 1; i--) {
		E m = {seg.query(i, posmn + 1, 0), seg.query(i, posmn + 1, 1)};
		E l = {seg.query(1, i - 1, 0), seg.query(1, i - 1, 1)};
		E nd = combine(l, r);
		cout << posmn + 1 << ' ' << i + 1 << ' ' << i + 2 << ' ' << n << ' ' << m.mn << ' ' << m.mx << ' ' << r.mn << ' ' << r.mx << ' ';
		int aa = max(0ll, nd.mn - m.mn);
		int bb = max(0ll, nd.mx - m.mx);
		cout << aa << ' ' << bb << '\n';
		res = min({res, mx - (mn + min(aa, bb))});
	}
	return res;
}
void solve() {

	cin >> n;

	vector<int> a(n);

	int mn = INF, posmn, mx = -INF, posmx;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] < mn) posmn = i, mn = a[i];
		if (a[i] > mx) posmx = i, mx = a[i];
	}

	seg.build(a);

	int res = cal(posmn, mx, mn);
	for (auto& i : a) i = -i;
	cout << res << '\n';
	seg.build(a);

	cout << min(res, cal(posmx, -mn, -mx)) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}