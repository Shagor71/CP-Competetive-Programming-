#include <bits/stdc++.h>
using namespace std;


#define int long long int
int e;

void solve() {

	int n, b, c;
	cin >> n >> b >> c;

	if (!b)
		cout << (n - 2 <= c ? (c < n ? n - 1 : n) : -1) << '\n';
	else {
		int lo = 0, hi = n - 1;
		// b*x + c <= n-1
		while (lo <= hi) {
			int x = lo + hi >> 1;
			__int128((__int128(b) * __int128(x)) + c) <= n - 1 ?  lo = x + 1 : hi = x - 1;
		}
		cout << n - lo << '\n';
	}

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--) {
		solve();
	}
}