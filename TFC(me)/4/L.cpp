#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long int
const int N = 1e5 + 5, M = 1e9 + 7;


void solve() {
	int n, m, d;
	cin >> n >> m >> d;

	vector<int> a(n), b(m);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ans = -1;
	for (auto i : a) {
		int x = i + d;
		int lo = 0, hi = m - 1, res = -1;
		while (lo <= hi) {
			int mm = lo + hi >> 1;
			if (i <= b[mm] and b[mm] <= x) res = max(res, b[mm]), lo = mm + 1;
			else if (b[mm] < i) lo = mm + 1;
			else hi = mm - 1;
		}
		if (~res) ans = max(ans, i + res);
	}

	for (auto i : b) {
		int x = i + d;
		int lo = 0, hi = n - 1, res = -1;
		while (lo <= hi) {
			int mm = lo + hi >> 1;
			if (i <= a[mm] and a[mm] <= x) res = max(res, a[mm]), lo = mm + 1;
			else if (a[mm] < i) lo = mm + 1;
			else hi = mm - 1;
		}
		if (~res) ans = max(ans, i + res);
	}

	cout << ans << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}