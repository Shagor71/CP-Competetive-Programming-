#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = 1e9 + 37, M = 1e9 + 7;
int e;

struct node {
	int sum, lmx, rmx, res;
	node() {
		sum = res = lmx = rmx = -MX;
	}
};
node ini;
struct SegmentTree {
	node t[3 * N];
	int n;

	node combine(node l, node r) {
		node tmp;
		tmp.sum = l.sum + r.sum;
		tmp.lmx = max({l.lmx, l.sum, l.sum + r.lmx, tmp.sum});
		tmp.rmx = max({r.rmx, r.sum, r.sum + l.rmx, tmp.sum});
		tmp.res = max({tmp.sum, tmp.lmx, l.rmx + r.lmx, tmp.rmx, l.res, r.res});
		return tmp;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id].sum = t[id].lmx = t[id].rmx = t[id].res = a[tl - 1]; // Index 1
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

	node query(int l, int r, int id, int tl, int tr) {
		if (tr < l or r < tl) return ini;
		if (l <= tl and tr <= r) return t[id];
		int tm = tl + tr >> 1;
		return combine(query(l, r, id << 1, tl, tm), query(l, r, id << 1 | 1, tm + 1, tr));
	}

	node query(int l, int r) {
		assert(n > 0);
		if (l > r) return ini;
		return query(l, r, 1, 1, n); // Index 1
	}

	void update(vector<int>&a, int pos, int val, int id, int tl, int tr) { // O(logn)
		if (tl == tr) {
			a[tl - 1] = val;
			t[id].sum = t[id].lmx = t[id].rmx = t[id].res = a[tl - 1];
			return;
		}
		int tm = tl + tr >> 1;
		pos <= tm ? update(a, pos, val, id << 1, tl, tm) : update(a, pos, val, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1]);
	}

	void update(vector<int>&a, int pos, int val) {
		assert(n > 0);
		update(a, pos, val, 1, 1, n); // Index 1
	}
} seg;

void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	seg.build(a);

	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t) {
			int l, r;
			cin >> l >> r;
			cout << seg.query(l, r).res << '\n';
			continue;
		}
		int i, x;
		cin >> i >> x;
		seg.update(a, i, x);
		//for (auto i : a) cout << i << ' '; cout << '\n';
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