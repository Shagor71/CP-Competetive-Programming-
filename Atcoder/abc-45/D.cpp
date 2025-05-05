#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;

map<pair<int, int>, bool> blk;

int cal(pair<int, int> xy, int h, int w) {
	int cnt = 0;
	if (h < xy.first + 2 or w < xy.second + 2) return 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			cnt += blk[make_pair(xy.first + i, xy.second + j)];
		}
	dbg(cnt)
	return cnt;
}
void solve() {

	int h, w, n;
	cin >> h >> w >> n;

	vector<pair<int, int>> p(n);
	for (auto& i : p) {
		cin >> i.first >> i.second;
		blk[i] = 1;
	}
	sort(p.begin(), p.end());

	vector<int> res(10, 0);

	for (auto i : p)
		res[cal(i, h, w)]++;


	for (int i = 1; i <= 9; ++i) cout << res[i] << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}