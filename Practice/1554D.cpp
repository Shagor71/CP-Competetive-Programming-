#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
const int N = 1e6 + 5, M = 1e9 + 7;

string get(int l) {
	string s = "";
	while (l--) s += 'a';
	return s;
}
void solve() {

	int n;
	cin >> n;

	if (n <= 2) {
		cout << (n == 1 ? "a" : "ab") << '\n';
		return;
	}

	if (n & 1) {
		n -= 2;
		cout << get(n + 1 >> 1) << "bc" << get(n >> 1) << '\n';
	} else {
		n--;
		cout << get(n + 1 >> 1) << "b" << get(n >> 1) << '\n';
	}
}
/*
	sollution:
	n = 8;
	aaaabaaa
	4321 321

	4321
	321
	oooo
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}