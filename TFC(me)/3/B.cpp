#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
//#define int long long
#define mk make_pair
const int N = 1e3 + 5, M = 1e6 + 7;

int dp[N][N];
int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};
int n, m;
char c[N][N];
bool ok(int x, int y) {
	return (1 <= x and x <= n and 1 <= y and y <= m);
}
struct st {
	int val, x, y;
};
struct cmp {
	bool operator() (st a, st b) {
		return a.val > b.val;
	}
};
void bfs(int x, int y) {
	priority_queue<st , vector<st>, cmp> q;
	q.push({0, x, y});
	dp[x][y] = 0;
	while (!q.empty()) {
		st now = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int X = now.x + xx[i], Y = now.y + yy[i];
			if (!ok(X, Y)) continue;
			if (c[X][Y] == c[now.x][now.y]) {
				if (dp[X][Y] <= dp[now.x][now.y]) continue;
				dp[X][Y] = dp[now.x][now.y];
				q.push({dp[X][Y], X, Y});
				continue;
			}
			if (dp[X][Y] > dp[now.x][now.y] + 1)
				dp[X][Y] = dp[now.x][now.y] + 1, q.push({dp[X][Y], X, Y});
		}
	}
	return;
}
void solve() {

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> c[i][j];
			dp[i][j] = M;
		}

	bfs(1, 1);

	cout << dp[n][m] << '\n';

	/*for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) cout << dp[i][j] << " \n"[j == m];*/
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}