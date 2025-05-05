#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
//#define int long long int
#define mk make_pair
const int N = 1e7 + 1, M = 1e9 + 7;

int csum[N], m[N], vis[N];

void sieve(int n) {
	for (int i = 2; i <= n; ++i) {
		if (vis[i]) continue;
		for (int j = i; j <= n; j += i) {
			csum[i] += m[j];
			vis[j] = 1;
		}
	}
	//for (int i = 1; i <= n; ++i) cout << csum[i] << " \n"[i == n];
	for (int i = 1; i <= n; ++i) csum[i] += csum[i - 1];
}
void solve() {

	int n;
	cin >> n;

	int mx = 0;
	for (int i = 1, x; i <= n; ++i) cin >> x, mx = max(mx, x), m[x]++;

	sieve(mx);

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << csum[min(r, mx)] - csum[min(l - 1, mx)] << '\n';
	}
}
/*
 1 2 5 5 6 6 2 3 7 8 8 9 10 10 9 7 3 4 4 1

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//int tc; cin >> tc; while (tc--)
	solve();
}