#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, mod = 998244353;

int e;
struct st {
	int d, pos;
};
bool ok(int atk, vector<st>&v, int m, int k) {
	vector<int> L, R;
	set<int> se;
	for (auto i : v) {
		int ext = m - ceil((double)i.d / atk);
		se.insert(i.pos);
		int l = i.pos - ext, r = i.pos + ext;
		if (l > r) continue;
		L.push_back(l);
		R.push_back(r);
		se.insert(l), se.insert(r);
	}
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());

	for (auto i : se) {
		int posi = upper_bound(L.begin(), L.end(), i) - L.begin();
		int neg = upper_bound(R.begin(), R.end(), i - 1) - R.begin();
		if (posi - neg >= k) return 1;
	}
	return 0;
}
void solve() {

	int n, m, k;
	cin >> n >> m >> k;

	vector<st> a(n);
	for (auto i : {1, 0})
		for (auto& x : a) cin >> (i ? x.d : x.pos);

	int lo = 1, hi = 1e9, res = -1;
	while (lo <= hi) {
		int atk = lo + hi >> 1;
		ok(atk, a, m, k) ? (res = atk, hi = atk - 1) : lo = atk + 1;
	}

	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}