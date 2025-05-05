#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7, M = 1e9 + 7;

void solve() {

	int a, b;
	cin >> a >> b;

	int res = 100;
	for (int c = a; c <= b; c++) {
		res = min(res, c - a + b - c);
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