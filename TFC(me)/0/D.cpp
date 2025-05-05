#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long

const int N = 1e6 + 5;

ll csum[N];
ll f(ll p) {
	return p * (p + 1) >> 1ll;
}
void solve() {
	int n; cin >> n;

	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		csum[x]++;
	}

	for (int i = 1; i < N; ++i) csum[i] += csum[i - 1];


	ll res = 0;
	for (int ai = 1; ai <= N - 5; ++ai) {
		ll frq = csum[ai] - csum[ai - 1];
		for (int k = 1; k * ai <= N - 5; ++k) {
			int l = ai * k, r = min(N - 4, ai * (k + 1) - 1);
			res += 1ll * k * (csum[r] - csum[l - 1]) * frq;
		}
		res -= f(frq);
	}

	cout << res << '\n';
}
/*


*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}