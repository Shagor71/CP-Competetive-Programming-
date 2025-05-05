#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int lo = 1, hi = n, res = 0;
	map<string, int> ache;
	while (lo <= hi) {
		int m = lo + hi >> 1;
		ache.clear();
		bool ok = 0;
		for (int i = 0; i + m <= n; ++i) {
			string sub = s.substr(i, m);
			l r = str
			if (ache[sub]) {
				if (ache[sub] <= i) {
					ok = 1;
					break;
				}
			}
			else
				ache[sub] = i + m;
		}
		ok ? (res = max(res, m), lo = m + 1) : hi = m - 1;
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