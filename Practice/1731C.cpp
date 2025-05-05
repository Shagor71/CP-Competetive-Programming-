#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long int
#define mk make_pair
const int N = 1e6 + 5, M = 1e9 + 7;

int m[N];
void solve() {

	int n;
	cin >> n;

	vector<int> a(n + 1), xr(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		xr[i] = xr[i - 1] ^ a[i];
	}
	//dbg(xr);

	/*for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			//int x = 0;
			//for (int k = j; k <= i; ++k) x ^= a[k];
			cout << '(' << j << ' ' << i << ' ' << (xr[i]^xr[j - 1]) << ')';
		} cout << '\n';
	}
	*/
	int res = (n * (n + 1)) >> 1;

	for (int i = 0; i * i <= n; ++i) {
		m[0] = 1;
		for (int j = 1; j <= n; ++j) {
			res -= m[xr[j] ^ (i * i)];
			m[xr[j]]++;
		}
		for (int j = 0; j <= n << 1; ++j) m[j] = 0;
	}
	//dbg(tmp, res, zero);
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