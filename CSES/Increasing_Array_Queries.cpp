#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;

struct st {
	int cost, range, val, tl, tr;
} t[N];
int csum[N];

struct SegmentTree {
	int n;

	st merge(st a, st b) {
		st tmp;
		tmp.tl = a.tl;
		tmp.tr = b.tr;
		int tm = (tmp.tl + tmp.tr) >> 1;
		tmp.range = max(a.range, b.range);
		tmp.val = a.range >= b.range ? a.val : b.val;
		int mn = min(a.range, b.tr);
		int left = a.val * (mn - tm) - (csum[mn] - csum[tm]);
		int right = b.val * (b.tr - mn) - (csum[b.tr] - csum[mn]);
		tmp.cost = a.cost + left + right;
		return tmp;
	}
	void build(vector<st> &a, int id, int tl, int tr) {
		if (tl == tr) {
			t[id] = {0, a[tl - 1].range, a[tl - 1].val, tl, tr}; // Index 1
			return;
		}
		int tm = tl + tr >> 1;
		build(a, id << 1, tl, tm), build(a, id << 1 | 1, tm + 1, tr);

		t[id] = merge(t[id << 1], t[id << 1 | 1]);
	}

	void build(vector<st> &a) {
		n = a.size();
		build(a, 1, 1, n); // Index 1
	}

	st query(int l, int r, int id, int tl, int tr) {
		if (l <= tl and tr <= r) return t[id];
		int tm = tl + tr >> 1;
		if (r <= tm) return query(l, r, id << 1, tl, tm);
		if (tm < l) return query(l, r, id << 1 | 1, tm + 1, tr);
		return merge(query(l, r, id << 1, tl, tm),
		             query(l, r, id << 1 | 1, tm + 1, tr));
	}

	int query(int l, int r) {
		assert(n > 0);
		if (l > r) return 0;
		return query(l, r, 1, 1, n).cost; // Index 1
	}
} seg;


void solve() {
	int n, q;
	cin >> n >> q;

	vector<st> a(n);

	int j = 1;
	for (auto& i : a) cin >> i.val, csum[j] = csum[j - 1] + i.val, j++;

	stack<pair<int, int>> st;
	for (int i = n - 1; i >= 0; --i) {
		int mx = -1, cnt = 0;
		while (!st.empty() and st.top().first < a[i].val) {
			mx = max(mx, a[st.top().second].range);
			st.pop();
			cnt++;
		}
		//cout << mx << " \n"[i == 0];
		if (st.empty()) a[i].range = n;
		else if (mx == -1) a[i].range = i + 1;
		else a[i].range = mx;

		st.push({a[i].val, i});
	}
	// for (auto i : a) cout << i.range << ' ';
	// cout << '\n';
	seg.build(a);

	// for (int i = 1; i < 18; ++i) cout << i << ' ' << t[i].cost << ' ' << t[i].range << ' ' << t[i].val << '\n';
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << seg.query(l, r) << '\n';
	}
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}