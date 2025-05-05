#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

void solve() {

	int n, k;
	cin >> n >> k;

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		res += (k <= x);
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