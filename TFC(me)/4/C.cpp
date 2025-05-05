#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long
const int N = 1e5 + 5, M = 1e9 + 7;


void solve() {
	int x, y, l, r;
	cin >> x >> y >> l >> r;

	if (y < l or r < x) {
		cout << "0\n";
		return;
	}

	cout << min(y, r) - max(x, l) << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}