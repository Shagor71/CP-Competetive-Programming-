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

//#define int long long
#define mk make_pair
const int N = 20 + 7, MX = N, M = 1e9 + 7;
int e;

int x[] = {0, 0, -1, 1};
int y[] = {1, -1, 0, 0};

char ch[N][N];
bool vis[N][N];
void solve() {

	int n, m, rr, cc;
	cin >> m >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
			if (ch[i][j] == '@') rr = i, cc = j;
			vis[i][j] = 0;
		}

	function<bool(int, int)> ok = [&](int i, int j)->bool {
		return (0 <= i and i < n and 0 <= j and j < m and !vis[i][j] and ch[i][j] == '.');
	};

	int res = 0;
	function<void(int, int)> dfs = [&](int r, int c)->void {
		res++;
		vis[r][c] = 1;
		for (int i = 0; i < 4; ++i)
			if (ok(r + x[i], c + y[i])) dfs(r + x[i], c + y[i]);
	};

	dfs(rr, cc);

	cout << "Case " << ++e << ": " << res << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}