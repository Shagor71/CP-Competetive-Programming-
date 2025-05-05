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
const int N = 1e5 + 5, M = 1e9 + 7;

struct E {
	int xr , ml;
	bool operator == (const E &a) const {
		return a.xr == xr && a.ml == ml;
	}
};
E operation(E hh, int x) {
	return {hh.xr ^ x, (hh.ml * x) % M};
}
map<int, bool> ma, mb;
void solve() {

	int n; cin >> n;

	vector<int> a(n + 1), b(n + 1);
	for (auto i : {1, 0})
		for (int j = 1; j <= n; ++j) cin >> (i ? a[j] : b[j]);

	vector<E> Ha(n + 1), Hb(n + 1);
	Ha[0] = Hb[0] = {0, 1};
	for (int i = 1; i <= n; ++i) {
		Ha[i] = (ma[a[i]] ? Ha[i - 1] : operation(Ha[i - 1], a[i]));
		Hb[i] = (mb[b[i]] ? Hb[i - 1] : operation(Hb[i - 1], b[i]));
		ma[a[i]] = mb[b[i]] = 1;
	}

	int q; cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << ((Ha[l] == Hb[r]) ? "Yes" : "No") << '\n';
	}
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}