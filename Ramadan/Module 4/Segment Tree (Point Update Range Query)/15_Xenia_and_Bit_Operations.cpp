#include <bits/stdc++.h>
using namespace std;

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

struct node {
	int x, stage;
};
node ini;
struct SegmentTree {
	node t[3 * N];
	int n;

	node combine(node l, node r) {
		node tmp;
		if (l.stage)
			tmp.x = (l.x | r.x), tmp.stage = 1 - l.stage;
		else
			tmp.x = (l.x ^ r.x), tmp.stage = 1 - r.stage;
		return tmp;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id] = {a[tl - 1], 1}; // Index 1
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
			t[id].x = a[pos - 1] = val;
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

	int n, q;
	cin >> n >> q;

	vector<int> a(1 << n);
	for (auto& i : a) cin >> i;

	seg.build(a);

	while (q--) {
		int i, x;
		cin >> i >> x;
		seg.update(a, i, x);
		cout << seg.query(1, 1 << n).x << '\n';
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