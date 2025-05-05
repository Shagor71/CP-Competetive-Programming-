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

	int n, k;
	cin >> n >> k;

	vector<int> a(n), b;
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());

	vector<int> trc;
	trc.push_back(0);
	for (int i = 1; i < n; ++i) if (a[i - 1] != a[i]) trc.push_back(i);

	int res = 0, sum = 0, i = 0, bad = 0, zero = 0;
	for (auto i : trc) {
		int sz = n - i, need = a[i] - bad;
		cout << need  << ' ';
		if (sum + need * sz >= k) {
			while (sum + need * sz > k) sz--;
			res += (sum + need * sz) + (i - (sz - zero));
			cout << res << '\n';
			return;
		}
		sum += need * sz;
		res += need * sz + (i - (sz - zero));
		bad += a[i];
		zero++;
	}

	cout << "-1\n";
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}