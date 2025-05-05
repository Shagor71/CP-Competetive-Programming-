#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n; cin >> n;

	vector<int> a(n + 1), len(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		len[i] = 1;
	}

	int res = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j * j <= i; ++j) {
			if (i % j) continue;
			int dv1 = j, dv2 = i / j;
			if (a[dv1] < a[i]) len[i] = max(len[i], len[dv1] + 1);
			if (a[dv2] < a[i]) len[i] = max(len[i], len[dv2] + 1);
		}
		res = max(res, len[i]);
	}

	cout << res << '\n';
}

int main() {
	int tc; cin >> tc; while (tc--)
		solve();
}