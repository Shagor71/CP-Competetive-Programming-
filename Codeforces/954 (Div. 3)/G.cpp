#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

void solve() {

	int n;
	cin >> n;

	vector<pair<int, int>> p;
	map<int, vector<int>> v;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		int gcd = __gcd(i, x);
		p.push_back({x / gcd, i / gcd});
		v[i / gcd].push_back(x / gcd);
	}
	sort(p.begin(), p.end());
	for (auto i : v) {
		sort(i.second.begin(), i.second.end());
		cout << i.first << ":\n  ";
		for (auto it : i.second) cout << it << ' ';
		cout << '\n';
	}

	for (auto i : p) cout << i.first << ' '; cout << '\n';
	for (auto i : p) cout << i.second << ' '; cout << '\n';

}
/*
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}