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


int f(vector<int>& a, int sz) {
	vector<int> odd(sz + 1, 0), even(sz + 1, 0);
	for (int i = 1; i < sz; ++i)
		i & 1 ? (odd[i] = odd[i - 1] + a[i] - a[i - 1], even[i] = even[i - 1]) : (even[i] = even[i - 2] + a[i] - a[i - 1], odd[i] = odd[i - 1]);

	int res = odd[sz - 1];
	if (sz & 1) {
		res = min(res, even[sz - 1]);
		for (int i = 1; i < sz - 1; ++i)
			if (i & 1)
				res = min(res, odd[i - 1] + a[i + 1] - a[i - 1] + even[sz - 1] - even[i + 1]);
			else
				res = min(res, odd[i - 1] + even[sz - 1] - even[i]);
	}

	return res;
}
void solve() {

	int n, k;
	cin >> n >> k;

	map<int, vector<int>> p;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		p[x % k].push_back(x / k);
	}

	int cnt = 0, res = 0;
	for (auto& i : p) {
		int sz = i.second.size();
		cnt += sz % 2;
		if ((n & 1 and cnt == 2) or (n % 2 == 0 and cnt == 1)) {
			cout << "-1\n";
			return;
		}
		sort(i.second.begin(), i.second.end());
		res += f(i.second, sz);
	}
	dbg(p);

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