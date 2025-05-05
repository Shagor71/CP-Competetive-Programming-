#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, INF = 1e6 + 6;

void solve() {

	int x, y, k;
	cin >> x >> y >> k;

	int res = 0;
	while (true) {
		while (x % y == 0) x /= k;
		k -= (x - (x % y));
		res += (x - x % y);
	}
	if (a == b) {

	}

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