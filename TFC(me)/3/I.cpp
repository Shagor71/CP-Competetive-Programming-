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

void solve() {

	string s;
	cin >> s;

	int a = 0, b = 0, ok = 1;
	for (auto i : s) {
		if (i == '.') ok = 0;
		else
			ok ? a = a * 10 + (i - '0') : b = b * 10 + (i - '0');
	}

	cout << a << ((0 <= b and b <= 2) ? "-" : (3 <= b and b <= 6) ? "" : "+") << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}