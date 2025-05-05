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


void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> csum(n + 1, 0);

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		csum[i] = csum[i - 1] + x;
		if (csum[i] <= k) res = i;
	}

	cout << res + 1 << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}