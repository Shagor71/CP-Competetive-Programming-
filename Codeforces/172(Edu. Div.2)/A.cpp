#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/

#define int long long


void solve() {
	int n, k; cin >> n >> k;

	vector<int> a(n);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());

	int sum = 0;
	while (!a.empty() and sum + a.back() <= k) {
		sum += a.back();
		a.pop_back();
	}

	cout << k - sum << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}