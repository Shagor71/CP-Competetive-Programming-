#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	for (int i = n - k + 1; i <= n; ++i) cout << a[i] << ' ';
	for (int i = 1; i <= n - k; ++i) cout << a[i] << ' ';

	cout << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}