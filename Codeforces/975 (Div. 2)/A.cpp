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

void solve() {

	int n; cin >> n;

	int odd = 0, even = 0;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		i & 1 ? odd = max(odd, x) : even = max(even, x);
	}

	cout << max(odd + ((n + 1) >> 1), even + (n >> 1)) << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}