#include <bits/stdc++.h>
using namespace std;


#define int long long int
const int N = 2e5 + 7;

int e;

int lr[N], rl[N], csum[N];

void precal(vector<int>&a, int v) {
	for (int i = 0; i <= a.size() + 1; ++i) lr[i] = rl[i] = 0;
	for (int i = 0; i < a.size(); ++i) {
		int tmp = 0;
		while (i < a.size() and tmp + a[i] < v) tmp += a[i], i++;
		if (i < a.size() and tmp + a[i] >= v) lr[i + 1] = 1;
	}
	for (int i = a.size() - 1; i >= 0; --i) {
		int tmp = 0;
		while (i >= 0 and tmp + a[i] < v) tmp += a[i], i--;
		if (i >= 0 and tmp + a[i] >= v) rl[i + 1] = 1;
	}
	csum[0] = 0ll;
	for (int i = 1; i <= a.size(); ++i) {
		lr[i] += lr[i - 1], rl[a.size() - i + 1] += rl[a.size() - i + 2];
		csum[i] = csum[i - 1] + a[i - 1];
	}
	//for (int i = 1; i <= a.size(); ++i) cout << lr[i] << " \n"[i == a.size()];
	//for (int i = 1; i <= a.size(); ++i) cout << rl[i] << " \n"[i == a.size()];
	return;
}
int res(vector<int>&a, int m) {
	int sum = 0, ans = -1;
	//cout << v << ":\n";
	for (int r = 1, l; r <= a.size(); ++r) {
		int ext_part = m - rl[r + 1];

		int lo = 0, hi = r, rs = -1;
		while (lo <= hi) {
			int ps = lo + hi >> 1;
			lr[ps] >= ext_part ? (rs = max(rs, csum[r] - csum[ps]), hi = ps - 1) : lo = ps + 1;
		}
		ans = max(ans, rs);
	}
	return ans;
}

void solve() {

	int n, m, v;
	cin >> n >> m >> v;
	e++;
	vector<int> a(n);
	for (auto& i : a) cin >> i;

	/*if (!ok(a, m, v)) {
		cout << "-1\n";
		return;
	}
	if (ok(a, m + 1, v)) {
		if (e == 337) {
			cout << "Hi\n";
			return;
		}
		cout << mx << '\n';
		return;
	}*/

	precal(a, v);

	cout << res(a, m) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--) {
		solve();
	}
}