#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;


void solve() {
	int n;
	cin >> n;

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		res += 3 * (x / 5);
		x %= 5;
		while (x > 0) {
			res++;
			x -= res % 3 ? 1 : 3;
		}
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