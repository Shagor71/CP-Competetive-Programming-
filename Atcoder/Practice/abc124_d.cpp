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
const int N = 1e6 + 5, mod = 1e9 + 7, INF = 1e9;


void solve() {

	string s;
	cin >> s;


	for (auto i : s) {
		if (i == '7') {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";


}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}