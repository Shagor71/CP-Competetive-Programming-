#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
const int N = 1e6 + 5, M = 1e9 + 7;

bool ok(int x) {
	for (int i  = 2; i * i <= x; i++) {
		if (x % i) continue;
		return 1;
	}
	return 0;
}
void solve() {

	int x, d;
	cin >> x >> d;

	int cnt = 0;
	while (x % d == 0) {
		cnt++;
		x /= d;
	}
	dbg(x, cnt, d);
	if (cnt > 1) {
		if (ok(x)) cout << "Yes\n";
		else {
			cnt--;
			if (cnt < 2) {
				cout << "No\n";
				return;
			}
			for (int i = 2; i * i <= d; ++i) {
				if (d % i) continue;
				if (i != d / i or x == 1) cout << "Yes\n";
				else {
					cout << ((i * x != d or cnt >= 3) ? "Yes" : "No") << '\n';
				}
				return;
			}
			cout << "No\n";
		}
	} else
		cout << "No\n";

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}