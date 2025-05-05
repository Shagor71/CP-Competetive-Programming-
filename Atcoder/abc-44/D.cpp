#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;

bool ok(int n, int b, int s) {
	int sum = 0;
	while (n) {
		sum += n % b;
		n /= b;
	}
	return sum == s;
}
void solve() {

	int n, s;
	cin >> n >> s;

	int sum = n - s;

	int res = 10e12;
	for (int x = 1; x * x <= sum; ++x) {
		if (sum % x) continue;
		if (ok(n, x + 1, s)) res = min(res, x + 1);
		if (ok(n, sum / x + 1, s)) res = min(res, sum / x + 1);
	}

	cout << (res == 10e12 ? -1 : res) << '\n';
}
/*
 d0 + d1k + d2k^2 + d3k^3 ____ = n
 d0 + d1 + d2 + d3 ____ = s

 d1(k - 1) = s - n
 d1x = sum
 sum%x == 0;



*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}