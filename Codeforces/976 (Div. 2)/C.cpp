#include <bits/stdc++.h>
using namespace std;
/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long int
#define mk make_pair
const int N = 2e5 + 5, M = 1e9 + 7, INF = 2e18;

void solve() {

	int b, c, d;
	cin >> b >> c >> d;

	if (b < c) {
		cout << "-1\n";
		return;
	}

	int a = d ^ b;
	/*bitset<8> h(a), h0(b), h1(c), h2(d), h3((b & c) ^ a);
	cout << h << '\n'; cout << h0 << '\n'; cout << h1 << '\n'; cout << h2 << '\n'; cout << h3 << '\n';*/

	if ((c & a) == 0) {
		cout << a << '\n';
		return;
	}
	a = (b & c) ^ a;

	cout << (((a | b) - (a & c) == d ? a : -1)) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}