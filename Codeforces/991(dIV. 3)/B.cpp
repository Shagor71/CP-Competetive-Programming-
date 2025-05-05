#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define ll long long
const int N = 4e5 + 7;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	ll od = 0, ev = 0, j = 0, x = 0, y = 0;
	for (auto& i : a) {
		cin >> i;
		j & 1 ? (od += i, x++) : (ev += i, y++);
		j++;
	}

	cout << ((od % x == 0 and ev % y == 0 and od / x == ev / y) ? "Yes" : "No") << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}