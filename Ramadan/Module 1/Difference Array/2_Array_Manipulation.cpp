#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> p;
	while (m--) {
		int a, b, k;
		cin >> a >> b >> k;
		p.push_back({a, k});
		p.push_back({b + 1, -k});
	}
	sort(p.begin(), p.end());

	int res = 0, cnt = 0;
	for (auto [x, k] : p) {
		cnt += k;
		res = max(res, cnt);
	}

	cout << res << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}