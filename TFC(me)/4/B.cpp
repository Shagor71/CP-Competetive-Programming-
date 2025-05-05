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
const int N = 1e3 + 5, M = 1e9 + 7;

struct st {
	int x, y;
};
string f(int t, char c) {
	string s = "";
	while (t--) s += c;
	return s;
}
void solve() {

	st a, b;
	int x, y;
	cin >> a.x >> a.y >> b.x >> b.y;
	b.x -= a.x, b.y -= a.y;

	string s = "";
	s += f(b.y, 'U') + f(b.x, 'R') + f(b.y, 'D')  + f(b.x + 1, 'L') + f(b.y + 1, 'U') + f(b.x + 1, 'R') + "DR"  + f(b.y + 1, 'D') + f(b.x + 1, 'L') + "U";
	cout << s;
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}