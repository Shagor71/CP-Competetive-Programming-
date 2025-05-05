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
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

struct node {
	int lf, nlf, nrt, rt;
	node() {
		lf = nlf = nrt = rt = 0;
	}
};
node ini;
struct SegmentTree {
	node t[3 * N];
	int n;

	node combine(node l, node r, int _l, int m, int _r) {
		node tmp;
		int ls = l.rt + r.nlf;
		int nls = l.nrt + r.lf;
		tmp.lf = ls, tmp.nlf = nls;
		tmp.rt = ls, tmp.nrt = nls;
		if (_l % 2 != m % 2) swap(tmp.lf, tmp.nlf);
		if (m % 2 != _r % 2) swap(tmp.rt, tmp.nrt);
		return tmp;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id].cnt[a[tl - 1]]++; // Index 1
			return;
		}
		int tm = tl + tr >> 1;
		build(a, id << 1, tl, tm), build(a, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1], tl, tm, tr);
	}

	void build(vector<int> &a) {
		n = a.size();
		build(a, 1, 1, n); // Index 1
	}

	node query(int l, int r, int id, int tl, int tr) {
		if (tr < l or r < tl) return ini;
		if (l <= tl and tr <= r) return t[id];
		int tm = tl + tr >> 1;
		return combine(query(l, r, id << 1, tl, tm), query(l, r, id << 1 | 1, tm + 1, tr), tl, tm, tr);
	}

	node query(int l, int r) {
		assert(n > 0);
		if (l > r) return ini;
		return query(l, r, 1, 1, n); // Index 1
	}

	void update(vector<int>&a, int pos, int val, int id, int tl, int tr) { // O(logn)
		if (tl == tr) {

			return;
		}
		int tm = tl + tr >> 1;
		pos <= tm ? update(a, pos, val, id << 1, tl, tm) : update(a, pos, val, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1], tl, tm, tr);
	}

	void update(vector<int>&a, int pos, int val) {
		assert(n > 0);
		update(a, pos, val, 1, 1, n); // Index 1
	}
} seg;

void solve() {



}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}