#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

void solve() {

	int n;
	cin >> n;

	vector<pair<int, int>> p(n);
	int j = 0;
	for (auto& i : p) {
		cin >> i.first;
		i.second = ++j;
	}
	sort(p.begin(), p.end());
	for (auto i : p) cout << i.second << ' ';
}
/*
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}