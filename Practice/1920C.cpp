#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e3 + 7, M = 998244353;

bool cal(vector<int>& a, int l) {
	int gcd = 0;
	for (int i = 0; i < l; ++i) {
		int x = i;
		for (int j = 0; j * l + i < a.size(); ++j) {
			gcd = __gcd(gcd, abs(a[x] - a[j * l + i]));
			if (gcd == 1) return 0;
			x = j * l + i;
		}
	}

	return 1;
}
// a%m = b%m
// |a%m - b%m| = 0;
// |a - b| % m = 0
// where m is factor of |a - b|
void solve() {
	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int res = 0;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i) continue;
		res += cal(a, i) + cal(a, n / i);
		if (i * i == n) res -= cal(a, i);
	}

	cout << res << '\n';
}
/*

   a s b



*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}