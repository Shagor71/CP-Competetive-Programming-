#include <bits/stdc++.h>
using namespace std;


#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7, INF = 1e9;

int csum[N];
int cal(vector<int> &a) {
	//if (ok) sort(a.begin(), a.end());
	csum[0] = 0;
	for (int i = 1; i <= a.size(); ++i) csum[i] = csum[i - 1] + a[i - 1] - a[0];
	int res = 0, sum = csum[a.size()];
	for (int i = 1; i <= a.size(); ++i) {
		int df = a[i - 1] - a[0];
		res += (sum - csum[i - 1]) - df * (a.size() - i + 1);
	}
	return res;
}
int g[1005][1005], x[1005][10005], y[1005][1005];
void solve() {

	int n, m;
	cin >> n >> m;

	map<int, int> x, y;
	set<int> se;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> g[i][j];
			se.insert(g[i][j]);
		}

	map<int, int> m;
	j = 0;
	for (auto i : se) m[i] = j++;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) x[g[i][j]].push_back(i);
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) y[g[j][i]].push_back(i);


	int res = 0;
	for (auto i : x)
		res += cal(i.second);

	for (auto i : y)
		res += cal(i.second);


	cout << (res << 1) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}