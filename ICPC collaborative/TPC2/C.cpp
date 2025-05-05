#include<bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long int
const int N = 1e6 + 9, INF = 2e9 + 7, ;

map<int, int> cv, cd, m;
void solve() {
	int n; cin >> n;


	int xr = 0, res = (n * (n + 1)) >> 1ll;
	set<int> se;

	cv[0] = 1;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		xr ^= x;
		if (m[x] & 1) se.insert(x);
		else if (se.find(x) != se.end()) se.erase(se.find(x));

		res -= (i & 1 ? cd[xr] : cv[xr]);

		if (!xr and !se.empty()) res++;

		i & 1 ? cd[xr]++ : cv[xr]++;
	}

	cv.clear(), cd.clear(), m.clear();

	cout << res << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc; cin >> tc; while (tc--)
		solve();
}