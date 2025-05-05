#include <bits/stdc++.h>
using namespace std;


#define int long long
#define mk make_pair
const int N = 700 + 7, MX = N, M = 1e9 + 7;
int e;

int sq(int n) {
	int sq = sqrtl(n);
	return sq * sq == n;
}
void solve() {

	int n; cin >> n;

	if (sq(n * (n + 1) / 2)) {
		cout << "-1\n";
		return;
	}

	for (int i = 2; i <= n; i += 2) {
		cout << i << ' ' << i - 1 << ' ';
	}
	if (n & 1) cout << n;
	cout << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}