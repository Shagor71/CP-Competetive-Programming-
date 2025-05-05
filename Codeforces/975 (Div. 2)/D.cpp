#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
#define mk make_pair
const int N = 1e6 + 5, M = 1e9 + 7;

vector<pair<int, int>> a(N);

bool possible(set<pair<int, int>>& tm, int cur) {
	int l = cur, r = cur, t = 1;
	set<pair<int, int>> tmp = tm;
	tmp.erase(tmp.find(a[cur]));
	while (!tmp.empty()) {
		int pos = tmp.begin()->second;
		if (l <= tmp.begin()->second and tmp.begin()->second <= r) {
			tmp.erase(tmp.begin());
			continue;
		}
		t += max(l - tmp.begin()->second, tmp.begin()->second - r);
		l = min(l, tmp.begin()->second);
		r = max(r, tmp.begin()->second);
		if (t > tmp.begin()->first) return 0;
		tmp.erase(tmp.begin());
	}
	return 1;
}
void solve() {

	int n; cin >> n;

	a.resize(n + 1);
	set<pair<int, int>> se;
	int mid = -1, mn = n + 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
		if (a[i].first < mn) mn = a[i].first, mid = i;
		se.insert(a[i]);
	}
	if (!possible(se, mid)) {
		cout << "0\n";
		return;
	}
	//dbg(se)
	int lo = 1, hi = mid, l = mid, r = mid;
	while (lo <= hi) {
		int m = lo + hi >> 1;
		possible(se, m) ? (l = m, hi = m - 1) : lo = m + 1;
	}
	lo = mid, hi = n;
	while (lo <= hi) {
		int m = lo + hi >> 1;
		possible(se, m) ? (r = m, lo = m + 1) : hi = m - 1;
	}

	cout << r - l + 1 << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}