#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;
int e;
int store[N][N];
void solve() {

	int n, k;
	cin >> n >> k;


	for (int i = 1; i <= n; ++i) store[0][i] = i;

	int mod = 0;
	while (true) {
		int j = 1;
		mod++;
		for (int i = 1; i <= n; i += 2, j++) store[mod][j] = store[mod - 1][i];
		for (int i = 2; i <= n; i += 2, j++) store[mod][j] = store[mod - 1][i];
		bool ok = 1;
		for (int i = 1; i <= n; ++i) {
			if (store[mod][i] != i) {
				ok = 0;
				break;
			}
		}
		for (int i = 1; i <= n; ++i) cout << store[mod][i] << ' '; cout << '\n';
		if (ok) break;
	}
	cout << k % mod << '\n';
	for (int i = 1; i <= n; ++i) cout << store[k % mod ? k % mod : mod][i] << " \n"[i == n];

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}