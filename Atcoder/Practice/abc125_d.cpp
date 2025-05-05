#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long int
const int N = 1e6 + 5, mod = 1e9 + 7, INF = 1e18;


void solve() {

	int n; cin >> n;

	int sz = 0, sum = 0, mn = INT_MAX;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		if (x < 0) sz++;
		sum += abs(x);
		mn = min(mn, abs(x));
	}
	//cout << sum << ' ' << sz << ' ' << mn << '\n';
	cout << sum - (sz & 1 ? mn << 1 : 0) << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}