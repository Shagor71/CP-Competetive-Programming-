#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int m[N];
void solve() {
	int n, k, Q, q;
	cin >> n >> k >> Q;

	q = Q;
	while (q--) {
		int x;
		cin >> x;
		m[x]++;
	}
	for (int i = 1; i <= n; ++i) {
		cout << (k - (Q - m[i]) <= 0 ? "No" : "Yes") << '\n';
	}
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}