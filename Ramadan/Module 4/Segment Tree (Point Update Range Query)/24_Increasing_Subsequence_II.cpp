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
	int res;
};
node ini;
int n;
struct SegmentTree {
	node t[3 * N];

	node combine(node l, node r) {
		node tmp;
		tmp.res = (l.res + r.res) % M;
		return tmp;
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

	void update(int pos, int val, int id, int tl, int tr) { // O(logn)
		if (tl == tr) {
			t[id].res += val;
			t[id].res %= M;
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

	cin >> n;

	vector<int> a(n);
	map<int, int> m;
	for (auto& i : a) cin >> i, m[i] = 1;

	int j = 1;
	for (auto [x, i] : m) m[x] = j++;

	for (auto i : a) {
		int x = m[i];
		seg.update(x, (x == 1 ? 0ll : seg.query(1, x - 1).res) + 1);
	}

	cout << seg.query(1, n).res << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}