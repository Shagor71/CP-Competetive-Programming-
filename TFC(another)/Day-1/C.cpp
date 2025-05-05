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

// ai xor aj < min(ai, aj)
// find max subset length
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int res = 0;
	for (int i = 30; i > -1 ; --i) {
		int tmp = 0;
		for (auto x : a) {
			if (((1 << i) ^ x) >= (1 << i)) continue;
			int y = ((1 << i) & x);
			bitset<4> bt(y);
			tmp += (y & (y - 1)) == 0;
		}
		res = max(res, tmp);
	}

	cout << res << '\n';

}
/*

	001
	010
	011

	10101
	10010
	1

    10101
    00100

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}