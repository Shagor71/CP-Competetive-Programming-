#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

const int N = 1e6 + 5, mod = 1e9 + 7;

void solve() {

	string s;
	cin >> s;


	for (int i = 1, j = 2; i < s.size(); ++i, j++) {
		if (s[i - 1] == s[i]) {
			cout << i << ' ' << i + 1 << '\n';
			return;
		}
		if (j < s.size() and s[i - 2] == s[i]) {
			cout << i - 1 << ' ' << i + 1 << '\n';
			return;
		}
	}

	cout << "-1 -1\n";

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}