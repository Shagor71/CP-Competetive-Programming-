#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
//#define int long long int
#define mk make_pair
const int N = 2e5 + 1, M = 1e7 + 7;

struct E {
	int csum, mx, mn;
};
E combine(E lf, E rt) {
	E tmp;
	tmp.csum = lf.csum + rt.csum;
	tmp.mx = max({lf.mx, lf.csum + rt.mx, tmp.csum});
	tmp.mn = min({lf.mn, lf.csum + rt.mn, tmp.csum});
	return tmp;
}
struct SegmentTree {
	E t[3 * N];
	int n;

	void clear(int n) {
		for (int i = 1; i < 3 * n; i++) {
			t[i] = {0, -M, M}; // Index 1
		}
		this->n = n;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id] = {a[tl - 1], a[tl - 1], a[tl - 1]}; // Index 1
			return;
		}
		int tm = tl + tr >> 1;
		build(a, id << 1, tl, tm), build(a, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1]);
		//dbg(tl, tr, t[id].csum, t[id].mx, t[id].mn);
	}

	void build(vector<int> &a) {
		n = a.size();
		build(a, 1, 1, n); // Index 1
	}

	E query(int l, int r, int id, int tl, int tr) {
		if (tr < l or r < tl) return {0, -M, M};
		if (l <= tl and tr <= r) return t[id];
		int tm = tl + tr >> 1;
		return combine(query(l, r, id << 1, tl, tm), query(l, r, id << 1 | 1, tm + 1, tr));
	}

	E query(int l, int r) {
		assert(n > 0);
		if (l > r) return {0, -M, M};
		return query(l, r, 1, 1, n); // Index 1
	}
	void update(int pos, E val, int id, int tl, int tr) { // O(logn)
		if (tl == tr) {
			t[id] = val;
			return;
		}
		int tm = tl + tr >> 1;
		pos <= tm ? update(pos, val, id << 1, tl, tm) : update(pos, val, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1]);
	}

	void update(int pos, E val) {
		assert(n > 0);
		update(pos, val, 1, 1, n); // Index 1
	}
} seg;

void solve() {

	int n, q;
	string s;
	cin >> n >> q >> s;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) a[i] = s[i] == '+' ? 1 : -1;

	seg.build(a);

	/*for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j) {
			int res = seg.query(i, j);
			cout << i << ' ' << j << ' ' << res.mx - res.mn + 1 << '\n';
		}*/
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (1 < l and r < n) {
			E LF = seg.query(1, l - 1);
			LF.mx = max(0, LF.mx), LF.mn = min(LF.mn, 0);
			int res = LF.mx - LF.mn + 1;
			seg.update(r, LF);
			//dbg(LF.mx, LF.mn)
			E RT = seg.query(r, n);
			cout << max(res, max(RT.mx, 0) - min(0, RT.mn) + 1) << '\n';
			seg.update(r, {a[r - 1], a[r - 1], a[r - 1]});
		}
		else if (1 < l) {
			E LF = seg.query(1, l - 1);
			//dbg(max(0, LF.mx), min(0, LF.mn))
			cout << max(0, LF.mx) - min(0, LF.mn) + 1 << '\n';
		}
		else if (r < n) {
			E RT = seg.query(r + 1, n);
			cout << max(0, RT.mx) - min(0, RT.mn) + 1 << '\n';
		}
		else cout << 1 << '\n';
	}


}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc; while (tc--)
		solve();
}