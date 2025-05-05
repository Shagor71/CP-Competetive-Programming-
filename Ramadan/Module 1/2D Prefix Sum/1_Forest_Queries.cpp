#include <bits/stdc++.h>
using namespace std;


const int N = 2e6 + 7, r = 1000;

int n, q;
int a[r + 5][r + 5];
void two_D() {
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			a[j][i] += a[j - 1][i];
		}
	}
	return;
}
int res(int x1, int y1, int x2, int y2) {
	return a[x2][y2] - (a[x2][y1 - 1] + a[x1 - 1][y2]) + a[x1 - 1][y1 - 1];
}
void solve() {

	cin >> n >> q;

	char ch[n + 1][n + 1];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> ch[i][j];
			a[i][j] = a[i][j - 1] + (ch[i][j] == '*');
		}
	}
	two_D();
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << res(x1, y1, x2, y2) << '\n';
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	//int tc; cin >> tc; while(tc--)
	solve();
}