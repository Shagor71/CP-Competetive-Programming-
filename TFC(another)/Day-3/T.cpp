#include <bits/stdc++.h>
using namespace std;


#define ll long long
const int N = 1e5 + 7, MX = N;


int combine(int x, int y) {
	return __gcd(x, y);
}
struct SegmentTree {
	int t[3 * MX];
	int n;

	void clear(int n) {
		for (int i = 1; i < 3 * n; i++) {
			t[i] = 0; // Index 1
		}
		this->n = n;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
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
} seg;

void solve() {
	int n; cin >> n;

	vector<int> a(n);
	for (auto &i : a) cin >> i;

	seg.build(a);

	vector<pair<int, int>> se;


	for (int l = 0; l < n; ++l) {
		int r = l - 1, gcd = 0, t = n;
		while (r < n - 1) {
			int lo = l, hi = n - 1, pos = r + 1;
			gcd = __gcd(gcd, a[r + 1]);
			while (lo <= hi) {
				int m = lo + hi >> 1;
				seg.query(l + 1, m + 1) == gcd ? (pos = max(pos, m), lo = m + 1) : hi = m - 1;
			}
			r = pos;
			cout << r << ' ';
			se.push_back({gcd, r - l + 1});
		}
		cout << '\n';
	}
	sort(se.begin(), se.end());

	//dbg(se)
	int i = 1;
	while (!se.empty() and i > n) {
		auto it = se.back();
		int sz = it.second, gcd = it.first;
		se.pop_back();
		while (i <= sz) {
			cout << gcd << " \n"[i == n];
			i++;
		}
	}

}
/*


*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}