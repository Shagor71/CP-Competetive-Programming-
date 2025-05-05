#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
//#define int long long
const int N = 4e5 + 7;

void solve() {
	int n, m;
	cin >> n >> m;

	int res = 0;
	while (n--) {
		string s;
		cin >> s;
		m -= s.size();
		res += m > -1;
	}

	cout << res << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}