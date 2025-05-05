#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
const int N = 1e3 + 5;

void solve() {

	int n;
	cin >> n;

	int sum = 0, mn = INT_MAX, mx = 0;
	vector<int> a(n), b(n);
	for (auto& i : a) cin >> i;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		if (a[i] > b[i]) swap(a[i], b[i]);
		sum += b[i] - a[i];
		mx = max(mx, a[i]), mn = min(mn, b[i]), ;
	}

	cout << sum + max(0ll, (mx - mn) << 1) << '\n';


}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}