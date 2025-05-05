#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/

#define int long long


void solve() {
	int n; cin >> n;

	vector<int> a(n + 1, 0);
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		a[x]++;
	}

	int one = 0, non = 0;
	for (int i = 1; i <= n; ++i)
		a[i] == 1 ? one++ : a[i] ? non++ : non;

	cout << ((one + 1 >> 1) << 1) + (non >> 1) + (non and one and one & 1 != non & 1) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}