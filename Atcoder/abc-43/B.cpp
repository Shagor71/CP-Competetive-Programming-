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

void solve() {

	string s, res = "";
	cin >> s;

	for (auto i : s) {
		if ( i == '0') res += '0';
		else if (i == '1') res += '1';
		else if (!res.empty()) res.erase(--res.end());
	}

	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}