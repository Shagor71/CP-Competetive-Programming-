#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/

#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7, INF = 1e9;

int csum[N];
int cal(vector<int> &a) {
	sort(a.begin(), a.end());
	csum[0] = 0;
	for (int i = 1; i <= a.size(); ++i) csum[i] = csum[i - 1] + a[i - 1] - a[0];
	int res = 0, sum = csum[a.size()];
	for (int i = 1; i <= a.size(); ++i) {
		int df = a[i - 1] - a[0];
		res += (sum - csum[i - 1]) - df * (a.size() - i + 1);
	}
	//dbg(a, res, sum)
	return res;
}
void solve() {

	int n, m;
	cin >> n >> m;

	map<int, vector<int>> x, y;
	for (int i = 1; i <= n; ++i)
		for (int j = 1, e; j <= m; ++j) {
			cin >> e;
			x[e].push_back(i), y[e].push_back(j);
		}


	int res = 0;
	for (auto& i : x) {
		//dbg(i.first)
		res += cal(i.second);
	}
	for (auto& i : y) {
		//dbg(i.first)
		res += cal(i.second);
	}


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