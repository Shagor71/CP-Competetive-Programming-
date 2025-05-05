#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
//#define int long long
const int N = 4e5 + 7;

bool ok(int x, int t, int s) {
	//dbg(x, t, s)
	if (!t) return x % 6 == 0 and x / 6 <= s;
	if (!s) return x % 2 == 0 and x / 2 <= t;
	if (s * 6 >= x) {
		x %= 6;
		return (x % 2 == 0 and x <= t * 2);
	} else {
		x -= s * 6;
		return (x % 2 == 0 and x <= t * 2);
	}
}
void solve() {
	string s;
	cin >> s;

	int sum = 0, tt[4] = {0};
	for (auto i : s) {
		sum += (i - '0');
		if ('2' <= i and i <= '3') tt[i - '0']++;
	}

	int baki = 9 - (sum % 9);
	if (baki % 9 == 0) {
		cout << "Yes\n";
		return;
	}

	int x[] = {baki, baki + 9, baki + 18, baki + 27, baki + 36};

	for (int i = 0; i < 5; ++i) {
		if (ok(x[i], tt[2], tt[3])) {
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
	int tc; cin >> tc; while (tc--)
		solve();
}