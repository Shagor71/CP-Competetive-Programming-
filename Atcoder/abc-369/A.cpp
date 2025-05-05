#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

void solve() {

	int a, b;
	cin >> a >> b;

	if (a == b) cout << "1\n";
	else cout << 2 + ((a - b) % 2 == 0) << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}