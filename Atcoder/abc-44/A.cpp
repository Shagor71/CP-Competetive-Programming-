#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;

void solve() {

	int n, k, x, y;
	cin >> n >> k >> x >> y;

	cout << min(n, k)*x + max(0ll, n - k)*y << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}