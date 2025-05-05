#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7, INF = 1e9;


void solve() {

	int n; cin >> n;

	vector<int> a, b;
	for (int i = 1, x; i <= n << 1; ++i) {
		cin >> x;
		i & 1 ? a.push_back(x) : b.push_back(x);
	}
	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());


	int res = 0;
	while (!a.empty()) {
		res += abs(a.back() - b.back());
		a.pop_back(), b.pop_back();
	}

	cout << res << '\n';


}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}