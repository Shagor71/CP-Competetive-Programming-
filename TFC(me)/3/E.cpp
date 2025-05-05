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
#define int long long
#define mk make_pair
const int N = 1e5 + 5, M = 1e9 + 7;

map<int, int> path, rpath;
void solve() {

	int n; cin >> n;

	int y = 0;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		path[y] = x;
		rpath[x] = y;
		y = x;
	}
	path[y] = -1;
	rpath[-1] = y;

	int q; cin >> q;
	while (q--) {
		int tp, x, y;
		cin >> tp;
		if (tp == 1) {
			cin >> x >> y;
			int tmp = path[x];
			path[x] = y, path[y] = tmp;
			rpath[tmp] = y, rpath[y] = x;
		}
		else {
			cin >> x;
			int r = path[x], l = rpath[x];
			path[l] = r;
			rpath[r] = l;
		}
	}

	int x = 0;
	while (path[x] != -1) {
		cout << path[x] << ' ';
		x = path[x];
	}
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}