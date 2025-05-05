#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

void solve() {

	int l, r;
	cin >> l >> r;

	if (l % 2 == 0) l++;

	int res = 0;
	for (int i = 1; l <= r; ++i, ++l) {
		if (i % 3 == 0) res++;
		if (i % 4 == 0) i = 0;
	}

	cout << res << '\n';
}
/*

		 1 2 3 4 5 6 7 8
		 -----   -----

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}