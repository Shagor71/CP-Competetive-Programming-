#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

void solve() {

	int n, l, r;
	cin >> n >> l >> r;

	vector<int> a(n + 1), csum(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		csum[i] = csum[i - 1] + a[i];
	}

	int pos = 0, res = 0;
	for (int i = 1; i <= n; ++i) {
		if (r < a[i]) pos = i;
		else if (l <= a[i] and a[i] <= r) res++, pos = i;
		else {
			int lo = pos, hi = i;
			while (lo <= hi) {
				int m = lo + hi >> 1;
				int sum = csum[i] - csum[m];
				if (l <= sum and sum <= r) {
					res++;
					pos = i;
					break;
				}
				sum < l ? hi = m - 1 : lo = m + 1;
			}
		}
	}
	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}