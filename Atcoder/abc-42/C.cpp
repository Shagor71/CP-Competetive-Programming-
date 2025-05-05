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
	string N, dgt = "0123456789";
	int k;
	cin >> N >> k;

	map<char, bool> m;

	while (k--) {
		char c; cin >> c;
		m[c] = 1;
	}

	string res = "";
	for (int i = 0; i < N.size(); ++i) {
		if (!m[N[i]]) res += N[i];
		else {
			for (char c = N[i] + 1; c <= '9'; ++c) {
				if (!m[c]) {
					i++;
					cout << res << c;
					for (char c = '0'; c <= '9'; ++c) {
						if (!m[c]) {
							while (i < N.size()) i++, cout << c;
							return;
						}
					}
					return;
				}
			}
			for (char c = '1'; c <= '9'; ++c) {
				if (!m[c]) {
					cout << c;
					for (char c = '0'; c <= '9'; ++c)
						if (!m[c]) {
							int t = N.size();
							while (t--) cout << c;
							return;
						}
				}
			}
		}
	}
	cout << res << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}