#include <bits/stdc++.h>
using namespace std;
/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long int
#define mk make_pair
const int N = 1e6 + 5, M = 1e9 + 7;

vector<int> res;

int j;
void magic(int sz, int cnt, int x) {
	j++;
	if (sz == 18) {
		res.push_back(x);
		return;
	}

	magic(sz + 1, cnt, x * 10 + 0);

	if (cnt < 3)
		for (int i = 1; i <= 9; ++i) magic(sz + 1, cnt + 1, x * 10 + i);
	return;
}
void solve() {

	int l, r;
	cin >> l >> r;
	// res[r] - res[l-1];
	cout << upper_bound(res.begin(), res.end(), r) - lower_bound(res.begin(), res.end(), l) << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	magic(0, 0, 0);
	res.push_back(1000000000000000000);
	//dbg(j);
	//cout << res.size() << '\n';
	//for (auto i : res) cout << i << ' ';
	int tc; cin >> tc; while (tc--)
		solve();
}