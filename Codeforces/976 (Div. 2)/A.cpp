#include <bits/stdc++.h>
using namespace std;
/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 2e5 + 5, M = 1e9 + 7;

void solve() {

	int n, k;
	cin >> n >> k;

	int res = 0;
	if (k == 1) {
		cout << n << '\n';
		return;
	}
	while (n) {
		res++;
		int tmp = 1;
		if (n < k) {
			res += n - 1;
			break;
		}
		while (tmp * k <= n)
			tmp *= k;
		n -= tmp;
	}

	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}