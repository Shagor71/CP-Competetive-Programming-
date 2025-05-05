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
int D[N];

void nod() {
	for (int i = 1; i < N; ++i) {
		int x = i;
		D[i] = 1;
		for (int j = 2; j * j <= x; ++j) {
			int cnt = 0;
			while (x % j == 0) x /= j, cnt++;
			D[i] *= cnt + 1;
		}
		if (x != 1) D[i] *= 2;
	}
	return;
}

struct node {
	int one_two = 0;
	ll res = 0;
};
node ini;
struct SegmentTree {
	node t[3 * N];
	int n;

	node combine(node l, node r) {
		node tmp;
		tmp.one_two = l.one_two + r.one_two;
		tmp.res = l.res + r.res;
		return tmp;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id] = {a[tl - 1] <= 2, a[tl - 1]}; // Index 1
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

	void update(int pos, int val, int id, int tl, int tr) { // O(logn)
		if (tl == tr) {
			t[id].one_two = val <= 2;
			t[id].res = val;
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

	void D_Q(vector<int>&a, int l, int r, int id, int tl, int tr) {
		if (tr < l or r < tl) return;
		if (l <= tl and tr <= r) {
			if (t[id].one_two == tr - tl + 1) return;
			if (tl == tr) {
				a[tl - 1] = D[a[tl - 1]];
				update(tl, a[tl - 1]);
				return;
			}
		}
		int tm = tl + tr >> 1;
		D_Q(a, l, r, id << 1, tl, tm), D_Q(a, l, r, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1]);
	}

	void D_Q(vector<int>&a, int l, int r) {
		assert(n > 0);
		D_Q(a, l, r, 1, 1, n);
	}
} seg;

void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	nod();
	seg.build(a);

	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;

		if (t == 2) {
			cout << seg.query(l, r).res << '\n';
			continue;
		}
		seg.D_Q(a, l, r);
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