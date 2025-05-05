#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

void solve() {

	int n;
	cin >> n;

	int a = 0, b = 0, aa  = -1, bb = -1;
	while (n--) {
		char c;
		int x;
		cin >> x >> c;
		if (aa == -1 and c == 'L') aa = x;
		if (bb == -1 and c == 'R') bb = x;
		c == 'L' ? (a += abs(aa - x), aa = x) : (b += abs(bb - x), bb = x);
	}

	cout << a + b << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}