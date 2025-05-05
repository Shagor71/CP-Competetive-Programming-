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
const int N = 1e6 + 7, MX = N, M = 1e9 + 7;
int e;

struct node {
	int res, ps, ng;
};
node ini;
struct SegmentTree {
	node t[3 * N];
	int n;

	node combine(node l, node r) {
		node tmp;
		int rs = min(l.ps, r.ng);
		tmp.res = l.res + r.res + rs;
		tmp.ps = l.ps + r.ps - rs;
		tmp.ng = l.ng + r.ng - rs;
		return tmp;
	}

	void build(string& a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id] = {0, a[tl - 1] == '(', a[tl - 1] == ')'}; // Index 1
			return;
		}
		int tm = tl + tr >> 1;
		build(a, id << 1, tl, tm), build(a, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1]);
	}

	void build(string& a) {
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

	string s;
	cin >> s;

	seg.build(s);

	int q; cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << seg.query(l, r).res * 2 << '\n';
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