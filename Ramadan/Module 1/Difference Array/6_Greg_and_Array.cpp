#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n, m, q;
	cin >> n >> m >> q;

	vector<ll> a(n);
	for (auto& i : a) cin >> i;

	vector<pair<pair<int, int>, int>> p(m);
	for (auto& [lr, d] : p) cin >> lr.first >> lr.second >> d;

	const int mx = max({n, m, q}) + 1;
	vector<ll> _rng(mx, 0);
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		_rng[l - 1]++, _rng[r]--;
	}
	for (int i = 0; i < mx; ++i)
		_rng[i] += i ? _rng[i - 1] : 0;

	int i = 0;
	vector<ll> rng(mx, 0);
	for (auto [lr, d] : p) {
		rng[lr.first - 1] += d * _rng[i];
		rng[lr.second] -= d * _rng[i];
		++i;
	}
	for (int i = 0; i < n; ++i) {
		rng[i] += i ? rng[i - 1] : 0;
		cout << a[i] + rng[i] << " \n"[i == n - 1];
	}
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}