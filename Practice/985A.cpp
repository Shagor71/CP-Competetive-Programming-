#include <bits/stdc++.h>
using namespace std;


#define int long long int
const int N = 2e5 + 7;

int e;


void solve() {

	int l, r, k;
	cin >> l >> r >> k;

	cout << max(0ll, r / k - l + 1) << '\n';
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