#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long

int get_posi_L(int lo, int hi, ll sum) {
	int pos = hi + 1, n = hi;
	while (lo <= hi) {
		int i = lo + hi >> 1;
		(sum <= cal(n) - cal(n - i + 1) + 1) ? (pos = i, hi = i - 1) : lo = i + 1;
	}
	return pos;
}
int get_posi_R(int lo, int hi, ll sum) {
	int pos = 0, n = hi;
	while (lo <= hi) {
		int i = lo + hi >> 1;
		(sum >= cal(n) - cal(n - i + 1)) ? (pos = i - 1, lo = i + 1) : hi = i - 1;
	}
	return pos;
}
void solve() {
	int n; cin >> n;

	vector<ll> a(n + 1), csum1(n + 1, 0), csum2(n + 1, 0), aisum(n + 1, 0);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		csum1[i] = csum1[i - 1] + a[i];
		sum += csum1[i];
		aisum[i] = sum;
	}

	for (int i = 1; i <= n; ++i) {
		csum2[i] = csum2[i - 1] + sum;
		//cout << sum << ' ';
		sum -= (n - i + 1) * a[i];
	}

	dbg(csum1, csum2, aisum);

	int q; cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;

		int res = 0, L = get_posi_L(1, n, l), R = get_posi_R(1, n, r);

		cout << L << ' ' << R << '\n';
		/*if(L > R) {

		} else {
			// for L
			ll tmp = (csum2[L] - csum2[L-1]) - aisum[];
			res += csum2[R] - csum[L-1];


		}

		cout << res << '\n';*/
	}
}
/*


*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}