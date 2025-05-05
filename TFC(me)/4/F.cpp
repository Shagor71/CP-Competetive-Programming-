#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/#define int long long
const int N = 1e5 + 5;


void solve() {
	int g, w, h;
	cin >> g >> w >> h;

	if ((0 < w and w < g and w < h) or (g < w and h < w and w < 0)) {
		cout << "-1\n";
		return;
	}

	int dw = abs(w), dh = abs(h), dg = abs(g);

	//wall not break;
	if ((w < 0 and w < g) or (g < w and 0 < w)) {
		cout << abs(g) << '\n';
	}
	//wall break;
	else if ((h < 0 and w < g) or (g < w and 0 < h)) {
		cout << (2 * dh + dg) << '\n';
	}
	else {
		cout << dg << '\n';
	}

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}