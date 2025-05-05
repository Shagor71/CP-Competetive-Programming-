#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

void solve() {

	int n, a, b;
	cin >> n >> a >> b;

	int gcd = __gcd(a, b);

	vector<int> mod(n);
	for (auto& i : mod) cin >> i, i %= gcd;
	sort(mod.begin(), mod.end());

	int res = mod.back() - mod.front();
	for (int i = 1; i < n; ++i)
		res = min(res, (mod[i - 1] + gcd) - mod[i]);

	cout << res << '\n';

}
/*

		 1 2 3 4 5 6 7 8
		 -----   -----

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}