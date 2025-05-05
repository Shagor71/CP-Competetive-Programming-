#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

void solve() {

	int n, q;
	cin >> n >> q;

	set<int> se;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		se.insert(x);
	}

	while (q--) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		auto it = se.end();
		it--;
		if (l <= *it and * it <= r) {
			int x = *it;
			se.erase(it);
			se.insert(c == '+' ? x + 1 : x - 1);
		}
		cout << *(--se.end()) << ' ';
	}
	cout << '\n';



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