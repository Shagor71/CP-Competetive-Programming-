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
	vector<ll> cnt;
	ll inv;
	node() {
		cnt.resize(41, 0);
		inv = 0;
	}
};
node ini;
struct SegmentTree {
	node t[3 * N];
	int n;

	node combine(node l, node r) {
		node tmp;
		tmp.inv = l.inv + r.inv;
		for (int i = 1; i <= 40; ++i) {
			tmp.cnt[i] = l.cnt[i] + r.cnt[i];
			if (!r.cnt[i]) continue;
			for (int j = i + 1; j <= 40; ++j)
				tmp.inv += r.cnt[i] * l.cnt[j];
		}
		return tmp;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id].cnt[a[tl - 1]]++; // Index 1
			return;
		}
		int tm = tl + tr >> 1;
		build(a, id << 1, tl, tm), build(a, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1]);
		//cout << tl << ' ' << tr << ' ' << t[id] << '\n';
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
			t[id].cnt[a[pos - 1]]--;
			a[pos - 1] = val;
			t[id].cnt[val]++;
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

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	seg.build(a);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r;
			cout << seg.query(l, r).inv << '\n';
			continue;
		}
		int ind, val;
		cin >> ind >> val;
		seg.update(a, ind, val);
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