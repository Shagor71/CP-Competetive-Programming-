#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
const int N = 1e6 + 5, M = 1e9 + 7;

int fct[N], ifct[N];

int exp(int a, int x) {
	if (!x) return 1;
	int res = exp(a, x >> 1);
	res = (res * res) % M;
	if (x & 1) res = (res * a) % M;
	return res;
}
void factorial(int n) {
	fct[0] = ifct[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fct[i] = (fct[i - 1] * i) % M;
		ifct[i] = exp(fct[i], M - 2);
	}
	return;
}
bool ok(int x, int a, int b) {
	while (x) {
		if (x % 10 != a and x % 10 != b) return 0;
		x /= 10;
	}
	return 1;
}
int ncr(int a, int b) {
	return (((fct[a + b] * ifct[a]) %  M ) * ifct[b]) % M;
}
void solve() {

	int a, b, n;
	cin >> a >> b >> n;

	factorial(n);

	int res = 0;
	for (int i = 0; i <= n; ++i) {
		int x = a * i + b * (n - i);
		if (ok(x, a, b)) {
			//dbg(i, x);
			res = (res + ncr(i, n - i)) % M;
		}
	}
	cout << res << '\n';


}
/*
	a = 2, b = 3, n = 6
	333333 6!/(0!*6!)
	233333 6!/(1!*5!)
	223333 6!/(2!*4!)
	222333 6!/(3!*3!)
	222233
	.......

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}