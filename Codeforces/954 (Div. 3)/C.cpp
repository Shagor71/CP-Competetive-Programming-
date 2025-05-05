#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n, m;
	string a, b;
	cin >> n >> m >> a;

	set<int> ind;
	while (m--) {
		int x;
		cin >> x;
		ind.insert(x);
	}
	cin >> b;
	sort(b.begin(), b.end());

	for (auto i : ind) {
		a[i - 1] = b.front();
		b.erase(b.begin());
	}
	cout << a << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}