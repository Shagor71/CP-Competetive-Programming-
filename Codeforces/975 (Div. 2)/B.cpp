#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
#define mk make_pair
const int N = 1e6 + 5, M = 1e9 + 7;

void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	map<int, int> res;
	for (int i = 1; i <= n; ++i) {
		int l = i - 1, r = n - i;
		res[n - 1 + l * r]++;
		if (i > 1)
			res[(i - 1) * (n - i + 1)] += a[i - 1] - a[i - 2] - 1;
	}
	while (q--) {
		int x; cin >> x;

		cout << res[x] << " \n"[q == 0];
	}

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}