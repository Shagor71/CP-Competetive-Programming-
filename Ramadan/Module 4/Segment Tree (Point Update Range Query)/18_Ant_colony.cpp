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
const int N = 2e5 + 7, inf = 1e9 + 7, M = 1e9 + 7;
int e;

struct node {
	int mn, gcd, cnt, res;
	node() {
		mn = inf, gcd = cnt = res = 0;
	}
};
node ini;
struct SegmentTree {
	node t[3 * N];
	int n;

	node combine(node l, node r) {
		node tmp;
		tmp.mn = min(l.mn, r.mn);
		tmp.gcd = __gcd(l.gcd, r.gcd);
		tmp.cnt = (l.mn == tmp.mn ? l.cnt : 0) + (r.mn == tmp.mn ? r.cnt : 0);
		tmp.res = tmp.mn == tmp.gcd ? tmp.cnt : 0;
		return tmp;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id].mn = t[id].gcd = a[tl - 1];
			t[id].cnt = 1;
			t[id].res = 0; // Index 1
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
} seg;

void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	seg.build(a);

	int q; cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << (r - l + 1) - seg.query(l, r).res << '\n';
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