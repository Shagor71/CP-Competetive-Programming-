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

	vector<int> a(n + 1), lr(n + 2, 0), rl(n + 2, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	for (int i = 1, j = n; i <= n; i++, j--) {
		lr[i] = __gcd(lr[i - 1], a[i]);
		rl[j] = __gcd(rl[j + 1], a[j]);
	}

	int res = 0;
	for (int i = 1; i <= n; ++i)
		res = max(res, __gcd(lr[i - 1], rl[i + 1]));

	cout << res << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}