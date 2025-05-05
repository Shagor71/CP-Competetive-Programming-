#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7, INF = 1e9;

int cal(pair<int, int>&a, pair<int, int>&b) {
	int c[] = {a.first, a.second, b.first, b.second};
	int cnt = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = i + 1; j < 4; ++j) cnt += (c[i] > c[j]);
	return cnt;
}
bool comp(pair<int, int>&a, pair<int, int>&b) {
	int invr1 = cal(a, b), invr2 = cal(b, a);
	if (invr1 == invr2) {
		int mx = max({a.first, a.second, b.first, b.second});
		return (mx != a.first and mx != a.second);
	}
	return invr1 < invr2;
}
void solve() {

	int n; cin >> n;

	vector<pair<int, int>> a(n);
	for (auto& i : a) cin >> i.first >> i.second;
	sort(a.begin(), a.end(), comp);

	for (auto i : a) cout << i.first << ' ' << i.second << ' ';
	cout << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}