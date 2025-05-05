#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	map<char, int> m;
	m.clear();
	for (auto i : s) m[i]++;
	vector<pair<int, char>> p;
	for (auto i : m) p.push_back({i.second, i.first});

	sort(p.begin(), p.end());

	string res = "";
	int i = 0, j = p.size() - 1;
	while (i < j) {
		res += p[i].second;
		res += p[j].second;
		p[i].first--;
		p[j].first--;
		if (!p[i].first) i++;
		if (!p[j].first) j--;
	}

	if (p[i].first) {
		while (p[i].first) {
			res = (res.back() == p[i].second ? p[i].second + res : res + p[i].second);
			p[i].first--;
		}
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