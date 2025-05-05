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

	map<char, int> m;
	for (auto i : s) m[i]++;

	for (auto i : m) {
		if (i.second & 1) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}