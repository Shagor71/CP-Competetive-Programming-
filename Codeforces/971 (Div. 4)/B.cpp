//codechef
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7, M = 1e9 + 7;

int e;
void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n + 1), pos(n + 1, 0), neg(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i == 1)  continue;
		a[i - 1] <= a[i] ? (pos[i] = pos[i - 1] + a[i] - a[i - 1], neg[i] = neg[i - 1]) : (neg[i] = neg[i - 1] + a[i - 1] - a[i], pos[i] = pos[i - 1]);
	}

	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		int ps = pos[r] - pos[l], ng = neg[r] - neg[l];
		int need = ps + ng - k;
		if (need < 1) {
			cout << "0\n";
			continue;
		}
		if (ps < ng) swap(ps, ng);
		if (ng << 1 >= need) {
			cout << min(ng, ((need + 1) >> 1)) << '\n';
		} else
			cout << ng + need - (ng << 1) << '\n';
		//cout << ps << ' ' << -ng << '\n';
	}
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}