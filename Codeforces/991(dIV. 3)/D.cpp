#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define ll long long
const int N = 1e5 + 7;

void solve() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		int mx = s[i] - '0', ps = i;
		for (int j = i; j < min(i + 9, (int)s.size()); ++j)
			if (mx < s[j] - '0' - (j - i)) mx =  s[j] - '0' - (j - i), ps = j;

		s[ps] = (char)mx + '0';
		for (int j = ps; j > i; j--) swap(s[j], s[j - 1]);
	}

	cout << s << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}