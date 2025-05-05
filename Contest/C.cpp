#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = 1e9 + 9, M = 998244353;
int e;

void solve() {

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<int> a(n);
	vector<pair<int, char>> BR;
	vector<int> B;
	for (auto& i : a) cin >> i;

	for (int i = 0; i < n;) {
		int mn = MX;
		if (s[i] == 'B') {
			while (i < n and s[i] == 'B') mn = min(mn, a[i]), i++;
			BR.push_back({mn, 'B'});
		}
		else {
			int sum = 0;
			while (i < n and s[i] == 'R') sum += a[i], i++;
			BR.push_back({sum, 'R'});
		}
	}
	dbg(BR);
	if (B.size() <= k) {
		cout << "0\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (BR[i].second == 'R') {
			if (i) B.push_back(min(BR[i - 1].first, BR[i].first));
			if (i + 1 != n)  B.push_back(min(BR[i + 1].first, BR[i].first));
		}
	}

	sort(B.begin(), B.end());
	while (k--) {
		B.pop_back();
	}


	cout << accumulate(B.begin(), B.end(), 0ll) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}