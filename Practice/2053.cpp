#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e3 + 7, M = 998244353;

int exp(int a, int p) {
	if (!p) return 1;
	int res = exp(a, p >> 1);
	res = res * res % M;
	if (p & 1) res = res * a % M;
	return res;
}
void solve() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n), b(n), ta, tb;
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	ta = a, tb = b;
	sort(ta.begin(), ta.end());
	sort(tb.begin(), tb.end());

	int res = 1;
	for (int i = 0; i < n; ++i) res = res * min(ta[i], tb[i]) % M;

	cout << res << ' ';

	while (q--) {
		int tp, i;
		cin >> tp >> i;
		i--;
		int prv_mn, cur_mn, ai = a[i], bi = b[i];
		dbg(ai);
		if (tp == 1) {
			a[i] = ++ai;
			int ps = lower_bound(ta.begin(), ta.end(), ai) - ta.begin();
			prv_mn = min(ta[ps - 1], tb[ps - 1]);
			ta[--ps] = ai;
			cur_mn = min(ta[ps], tb[ps]);
			dbg(ps, ai, ta[ps]);
		} else {
			b[i] = ++bi;
			int ps = lower_bound(tb.begin(), tb.end(), bi) - tb.begin();
			prv_mn = min(ta[ps - 1], tb[ps - 1]);
			tb[--ps] = bi;
			cur_mn = min(ta[ps], tb[ps]);
		}
		dbg(ta, tb);
		res = res * exp(prv_mn, M - 2) % M * cur_mn % M;
		cout << res << " \n"[q == 0];
	}

}
/*
          2
	1 1 1 1 2 2 2 2 3 3
	1 1 1 1 5 5 6 6 7 8

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}