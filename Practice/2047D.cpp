#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/

const int N = 4e5 + 7;

void solve() {
	int n; cin >> n;

	vector<int> a(n + 1), b, sml(n + 2);
	a[0] = 1e9 + 7;
	int pos = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] <= a[pos]) pos = i;
	}

	int cnt = 1, sheshe = a[0];
	for (int i = 1; i < pos; ++i) {
		if (a[i] == a[pos]) cnt++;
		else
			b.push_back(a[i] + 1), sheshe = min(sheshe, a[i] + 1);
	}

	sml[n + 1] = 1e9 + 7;
	for (int i = n; i > pos; i--) sml[i] = min(a[i], sml[i + 1]);

	for (int i = pos + 1; i <= n; ++i) {
		if (a[i] > sml[i + 1] or a[i] > sheshe) b.push_back(a[i] + 1), sheshe = min(sheshe, a[i] + 1);
		else b.push_back(a[i]);
	}
	sort(b.begin(), b.end());

	while (cnt--) cout << a[pos] << ' ';
	for (auto i : b) cout << i << ' ';
	cout << '\n';
}
/*
	6
	1 4 3 2 4 5 5
	0 1 0 1 0
	1 2 5 5 3
	1 2
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}