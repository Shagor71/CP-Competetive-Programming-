#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

void solve() {

	int a, b;
	cin >> a >> b;

	int gcd = __gcd(a, b);
	int res = 0;
	for (int i = 2; i * i <= gcd; ++i) {
		if (gcd % i) continue;
		res++;
		while (gcd % i == 0) gcd /= i;
	}
	cout << res + (gcd > 1) + 1 << '\n';

}
/*
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}