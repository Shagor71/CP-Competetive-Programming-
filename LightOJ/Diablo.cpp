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

#define int long long
#define mk make_pair
const int N = 1e6 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n, q;
	cin >> n >> q;

	o_set<pair<int, int>> se;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		se.insert({i, x});
	}

	cout << "Case " << ++e << ":\n";
	while (q--) {
		char tp;
		int xp;
		cin >> tp >> xp;
		if (tp == 'c') {
			if (se.size() < xp) cout << "none\n";
			else {
				auto it = se.find_by_order(xp - 1);
				cout << it->second << '\n';
				se.erase(it);
			}
			continue;
		}
		n++;
		se.insert({n, xp});
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