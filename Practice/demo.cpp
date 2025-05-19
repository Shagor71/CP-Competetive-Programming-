#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int minTimeToReach(vector<vector<int>>& moveTime) {
	int n = moveTime.size();
	int m = moveTime[0].size();
	int x[] = {0, 0, 1, -1};
	int y[] = {1, -1, 0, 0};
	priority_queue<pair<int, array<int, 3>>, vector<pair<int, array<int, 3>>>, greater<pair<int, array<int, 3>>>> pq;
	vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (2, INT_MAX)));
	dp[0][0][0] = dp[0][0][1] = 0;
	pq.push({0, {0, 0, 1}});
	while (!pq.empty()) {
		int res = pq.top().first;
		int r = pq.top().second[0];
		int c = pq.top().second[1];
		int move = pq.top().second[2];
		pq.pop();
		if (r == n - 1 and c == m - 1) {
			//dbg(dp);
			return res;
		}
		for (int i = 0; i < 4; ++i) {
			int ro = r + x[i];
			int co = c + y[i];
			if (0 <= ro and ro < n and 0 <= co and co < m) {
				int need = max(res, moveTime[ro][co]) + (1 - move) + 1;
				if (need < dp[ro][co][1 - move]) {
					dp[ro][co][1 - move] = need;
					pq.push({need, {ro, co, 1 - move}});
				}
			}
		}
	}
	return -1;
}
void solve() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> moveTime(n, vector<int>(m));
	for (auto& i : moveTime)
		for (auto& j : i) cin >> j;

	cout << minTimeToReach(moveTime) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}