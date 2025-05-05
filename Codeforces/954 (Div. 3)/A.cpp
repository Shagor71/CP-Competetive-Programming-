#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

int a[3];
int f(int x) {
	int rs = 0;
	for (int i = 0; i < 3; ++i) rs += abs(x - a[i]);
	return rs;
}
void solve() {
	cin >> a[0] >> a[1] >> a[2];

	int res = INT_MAX;
	for (auto i : {0, 1, 2}) res = min(res, f(a[i]));

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