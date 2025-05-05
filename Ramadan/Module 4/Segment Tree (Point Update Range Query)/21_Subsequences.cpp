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
const int N = 1e5 + 7, MX = N, M = 1e9 + 7;
int e;

struct node {
	ll res = 0;
};
node ini;
int n;
node t[3 * N][12];
struct SegmentTree {

	node combine(node l, node r) {
		node tmp;
		tmp.res = l.res + r.res;
		return tmp;
	}

	node query(int l, int r, int id, int tl, int tr, int len) {
		if (tr < l or r < tl) return ini;
		if (l <= tl and tr <= r) return t[id][len];
		int tm = tl + tr >> 1;
		return combine(query(l, r, id << 1, tl, tm, len), query(l, r, id << 1 | 1, tm + 1, tr, len));
	}

	node query(int l, int r, int len) {
		assert(n > 0);
		if (l > r) return ini;
		return query(l, r, 1, 1, n, len); // Index 1
	}

	void update(int pos, ll val, int id, int tl, int tr, int len) { // O(logn)
		if (tl == tr) {
			t[id][len].res = val;
			return;
		}
		int tm = tl + tr >> 1;
		pos <= tm ? update(pos, val, id << 1, tl, tm, len) : update(pos, val, id << 1 | 1, tm + 1, tr, len);
		t[id][len] = combine(t[id << 1][len], t[id << 1 | 1][len]);
	}

	void update(int pos, ll val, int len) {
		assert(n > 0);
		update(pos, val, 1, 1, n, len); // Index 1
	}
} seg;


void solve() {

	int k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	if (!k) {
		cout << n << '\n';
		return;
	}

	ll res = 0;
	for (auto i : a) {
		if (i > 1) res += seg.query(1, i - 1, k).res;
		for (int l = k; l; l--)
			seg.update(i, l == 1 ? 1ll : seg.query(1, i - 1, l - 1).res, l);
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