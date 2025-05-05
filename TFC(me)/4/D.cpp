#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long
const int N = 1e5 + 5, M = 1e9 + 7;


void solve() {
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < min(a.size(), b.size()); ++i) {
		if (a[i] != b[i]) {
			cout << i + 1 << '\n';
			return;
		}
	}
	cout << min(a.size(), b.size()) << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}