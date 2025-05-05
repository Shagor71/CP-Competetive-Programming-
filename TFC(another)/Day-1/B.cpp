#include <bits/stdc++.h>
using namespace std;
/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e5 + 5, M = 998244353;

int csum[N];
int cal(int x, int j) {
	int r = x / j, l = x / (j + 1);
	return j * (csum[r] - csum[l] - (l < x and x <= r));
}
void solve() {

	int n; cin >> n;

	set<int> se;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		se.insert(x);
		csum[x]++;
	}

	for (int i = 1; i <= (*se.rbegin()); ++i) csum[i] += csum[i - 1];

	int res = 0;
	for (auto i : se) {
		for (int j = 1; j * j <= i; ++j) {
			if (i % j) continue;
			res += cal(i, j) + (j * j == i ? 0ll : cal(i, i / j));
		}
	}
	cout << res << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}