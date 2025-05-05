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
const int N = 2e5 + 5, M = 1e9 + 7;

void solve() {

	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<int, int>> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int> csum(n + 1, 0), v;
	for (int i = 1; i <= n; ++i) csum[i] = csum[i - 1] + a[i].first, v.push_back(a[i].first);


	k -= csum[n];
	//dbg(k, v);
	//dbg(csum)
	vector<pair<int, int>> res(n + 1);
	for (int i = 1; i <= n; ++i) {
		if (a[i].first + k <= a[n - m + 1].first) {
			res[a[i].second] = (a[i].first + k < a[n - m + 1].first ? mk(-1, -1) : mk(0, -1));
		}
		else {
			int lo = a[i].first, hi = lo + k, H = -1, l = n - m + 1;
			l += (l <= i);
			//dbg(lo, hi)
			while (lo <= hi) {
				int hieght = lo + hi >> 1;
				int r = upper_bound(v.begin(), v.end(), hieght) - v.begin();
				int boro = n - r;
				int sum = boro * hieght + csum[r] - csum[l - 1];
				int total = m * hieght, need = total - sum;
				//dbg(l, r, hieght, boro, total, sum, need)
				if (need >= k - (hieght - a[i].first)) H = hieght, hi = hieght - 1;
				else lo = hieght + 1;
			}
			res[a[i].second] = {H - a[i].first, H};
		}
	}
	//cout << res[6].first << ' ' << res[6].second << '\n';
	for (int i = 1; i <= n; ++i) cout << res[i].first << " \n"[i == n];
	//res.erase(res.begin());
	//dbg(res);
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}