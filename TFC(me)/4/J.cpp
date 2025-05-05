#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
//#define int long long
const int N = 1e2 + 5, M = 1e9 + 7;


void solve() {

	int n, l, r;
	cin >> n >> l >> r;

	int xr = 0;
	while (n--) {
		int x; cin >> x;
		xr ^= ((x % (r + l)) / l);
	}

	cout << (xr ? "First" : "Second") << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}