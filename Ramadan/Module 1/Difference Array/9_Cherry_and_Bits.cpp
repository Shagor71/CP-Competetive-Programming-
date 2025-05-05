#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 1e3 + 7, MX = N, M = 1e9 + 7;
int e;

int g[N][N], a[N][N];
void TwoDSum(int n, int m) {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];
	return;
}
void solve() {

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			char c; cin >> c;
			a[i][j] = c - '0';
		}

	int q; cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x2++, y2++;
		g[x1][y1]++;
		g[x1][y2]--;
		g[x2][y1]--;
		g[x2][y2]++;
	}

	TwoDSum(n, m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << (2 + (g[i][j] + a[i][j]) % 2) % 2;
		cout << '\n';
	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}