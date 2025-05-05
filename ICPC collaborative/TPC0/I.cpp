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

int zel(int k, int m, int d, int c)
{
	int f = k + ((13 * m - 1) / 5) + d + d / 4 + c / 4 - 2 * c;
	return f;
}

void solve() {
	int n;
	cin >> n;
	int sol = 0;
	bool tr = false;
	if (n % 4 == 0)	tr = true;
	n--;
	int x = zel(1, 11, n % 100, n / 100);
	x %= 7;
	if (x < 0)	x += 7;

	if (x == 0)	x = 6;
	else	x--;

	// cout << x << '\n';

	x = 7 - x;
	if (tr)
	{
		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 1;
		sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 2;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 2;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 2;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 2;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;
	}
	else
	{
		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		if (x == 7)	sol += 4;
		else	sol += 5;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 2;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 2;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 2;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 2;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;

		x -= 3;
		if (x < 0)	x += 7, sol += 6;
		else	sol += 5;
		if (x == 0)	x = 7;
	}
	cout << sol << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int tc; cin >> tc; while (tc--)
	solve();
}