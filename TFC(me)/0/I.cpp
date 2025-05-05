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
const int N = 1e5 + 5, M = 1e9 + 7;


void solve() {

	int n; cin >> n;

	if (n & 1) {
		cout << "0\n";
		return;
	}

	int res = 0, f = 10;
	while (f <= n) {
		res += n / f;
		f *= 5;
	}

	cout << res << '\n';


}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}