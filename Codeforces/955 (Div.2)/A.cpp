#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

void solve() {

	int a, b, x, y;
	cin >> a >> b >> x >> y;

	cout << ((a < b and x > y) or (a > b and x < y) ? "No" : "Yes") << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}