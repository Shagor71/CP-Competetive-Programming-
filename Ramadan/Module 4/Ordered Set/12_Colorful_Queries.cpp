#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> pos(n + 1, 0);
	o_set<int> se;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		if (!pos[x]) pos[x] = i;
		se.insert(i);
	}

	dbg(se);

	int i = 0;
	while (q--) {
		int x; cin >> x;
		cout << se.order_of_key(pos[x]) + 1 << '\n';
		se.erase(--se.lower_bound(pos[x]));
		pos[x] = i;
		se.insert(i);
		dbg(se);
		i--;
	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}