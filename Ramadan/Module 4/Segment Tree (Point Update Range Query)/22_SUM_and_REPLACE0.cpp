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
	D[1] = 1;
	for (int i = 2; i < N; ++i) {
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
	ll res = 0;
};
node ini;
struct SegmentTree {
	node t[3 * N];
	int n;

	node combine(node l, node r) {
		node tmp;
		tmp.res = l.res + r.res;
		return tmp;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id].res = a[tl - 1]; // Index 1
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
} seg;

void solve() {

	nod();

	int n, q;
	cin >> n >> q;


	vector<int> a(n);
	set<int> se;
	int j = 1;
	for (auto& i : a) {
		cin >> i;
		if (D[i] != i) se.insert(j);
		j++;
	}

	seg.build(a);

	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;

		if (t == 2) {
			cout << seg.query(l, r).res << '\n';
			continue;
		}
		auto id = se.lower_bound(l);
		vector<int> v;
		for (; id != se.end() and * id <= r; ++id) {
			int x = *id;
			a[x - 1] = D[a[x - 1]];
			seg.update(x, a[x - 1]);
			if (a[x - 1] == D[a[x - 1]]) v.push_back(x);
		}
		while (!v.empty()) {
			se.erase(se.lower_bound(v.back()));
			v.pop_back();
		}
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