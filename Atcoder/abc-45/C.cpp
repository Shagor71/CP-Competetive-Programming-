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
const int N = 1e6 + 5, mod = 1e9 + 7;


void solve() {

	string s;
	cin >> s;

	int res = 0;
	//reverse(s.begin(), s.end());

	for (int mask = 0; mask < 1 << s.size(); ++mask) {
		int track = 0;
		for (int i = 0; (1 << i) <= mask; i++) {
			if ((1 << i) & mask) {

			}
		}
	}

	cout << mgc(0, 0);
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}