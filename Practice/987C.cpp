#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

const int N = 1e5 + 7;

int e;

void solve() {

	int n; cin >> n;

	if (n & 1) {
		// a^2 + b^2 = c^2
		// x  +  y =  z
		// where x = 9, y = 16 & z = 25 perfect square
		if (n < 26) cout << "-1\n";
		else {
			int a[n + 1];
			a[1] = a[10] = a[26] = 1;
			a[11] = a[27] = 2;
			for (int i = 2; i < 9; i += 2) a[i] = a[i + 1] =  i + 1;
			for (int i = 12; i < 25; i += 2) a[i] = a[i + 1] = i;
			for (int i = 28; i < n; i += 2) a[i] = a[i + 1] = i;
			for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
		}
	} else
		for (int i = 1; i << 1 <= n; ++i) cout << i << ' ' << i << " \n"[i << 1 == n];

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}