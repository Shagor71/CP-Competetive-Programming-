#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 1e6 + 7, MX = N, M = 1e9 + 7;
int e;

int combine(int x, int y) {
	return x + y;
}
//int t[3 * N];
struct SegmentTree {
	int t[3 * MX];
	int n;

	void clear(int n) {
		for (int i = 1; i < 3 * n; i++) {
			t[i] = 0; // Index 1
		}
		this->n = n;
	}

	void build(vector<int>&a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id] = a[tl - 1]; // Index 1
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

	int query(int l, int r, int id, int tl, int tr) {
		if (tr < l or r < tl) return 0ll;
		if (l <= tl and tr <= r) return t[id];
		int tm = tl + tr >> 1;
		return combine(query(l, r, id << 1, tl, tm), query(l, r, id << 1 | 1, tm + 1, tr));
	}

	int query(int l, int r) {
		assert(n > 0);
		if (l > r) return 0;
		return query(l, r, 1, 1, n); // Index 1
	}

	void update(int pos, int val, int id, int tl, int tr) { // O(logn)
		if (tl == tr) {
			t[id] = val;
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

	int n, q;
	cin >> n >> q;

	vector<int> aa(n);
	set<int> se;
	for (auto& i : aa) cin >> i, se.insert(i);

	vector < pair<char, pair<int, int>>> p(q);
	for (auto& [c, pr] : p) {
		cin >> c >> pr.first >> pr.second;
		se.insert(pr.second);
		if (c == '?') se.insert(pr.first);
	}

	vector<int> a(se.size());
	map<int, int> m;
	int j = 0;
	for (auto i : se) m[i] = j++;

	for (auto& i : aa) i = m[i], a[i]++;
	for (auto& [c, pr] : p)
		pr = {c == '?' ? m[pr.first] : pr.first, m[pr.second]};


	seg.build(a);
	dbg(aa);
	dbg(p);
	dbg(a);

	for (auto [c, pr] : p) {
		if (c == '?')
			cout << seg.query(pr.first + 1, pr.second + 2) << '\n';
		else {
			int pos = aa[pr.first - 1];
			a[pos]--;
			seg.update(pos, a[pos]);
			pos = pr.second, a[pos]++;
			aa[pr.first - 1] = pr.second;
			seg.update(pos, a[pos]);
		}
		dbg(aa);
		dbg(a);
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