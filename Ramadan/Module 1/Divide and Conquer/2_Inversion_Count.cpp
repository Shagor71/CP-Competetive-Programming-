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
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
ll ans;

ll merge(vector<int>&a, int l, int m, int r) {
	ll res = 0;
	for (int i = m + 1; i <= r; ++i) {
		int lo = l, hi = m;
		ll rs = 0;
		while (lo <= hi) {
			int mid = lo + hi >> 1;
			a[mid] > a[i] ? (rs = m - mid + 1, hi = mid - 1) : lo = mid + 1;
		}
		res += rs;
	}
	//cout << l << ' ' << m << ' ' << m + 1 << ' ' << r << ' ' << res << '\n';
	vector<int> tmp;
	int i = l, j = m + 1;
	while (i <= m and j <= r)
		a[i] <= a[j] ? (tmp.push_back(a[i]), ++i) : (tmp.push_back(a[j]), ++j);

	while (i <= m) tmp.push_back(a[i++]);
	while (j <= r) tmp.push_back(a[j++]);

	for (int i = l, j = 0; i <= r; ++i, ++j) a[i] = tmp[j];

	return res;
}
void call(vector<int>&a, int l, int r) {
	if (l == r) return;
	int m = l + r >> 1;
	call(a, l, m), call(a, m + 1, r);
	ans += merge(a, l, m, r);
}
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	ans = 0;
	call(a, 0, n - 1);

	cout << ans << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}