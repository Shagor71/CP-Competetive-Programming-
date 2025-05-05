#include <bits/stdc++.h>
using namespace std;


#define int long long
const int N = 1e6 + 7, mod = 998244353;

int e;
struct st {
	int d, pos;
};
bool ok(int atk, vector<st>&v, int m, int k) {
	map<int, int> mp;
	for (auto i : v) {
		int l = max(1ll, 0ll + i.pos - m + (i.d + atk - 1) / atk), r = min(0ll + i.pos + m - (i.d + atk - 1) / atk, 1000000000ll);
		if (l > r) continue;
		mp[l]++, mp[r + 1]--;
	}

	int csum = 0;
	for (auto &[x, y] : mp) {
		csum += y;
		if (csum >= k) return 1;
	}
	return 0;
}
void solve() {

	int n, m, k;
	cin >> n >> m >> k;

	vector<st> a(n);
	for (auto i : {1, 0})
		for (auto& x : a) cin >> (i ? x.d : x.pos);

	int lo = 1, hi = 1e9, res = -1;
	while (lo <= hi) {
		int atk = lo + hi >> 1;
		ok(atk, a, m, k) ? (res = atk, hi = atk - 1) : lo = atk + 1;
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