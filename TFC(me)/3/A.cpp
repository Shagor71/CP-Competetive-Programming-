#include <bits/stdc++.h>
using namespace std;

/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
*//*
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

	int a, b;
	cin >> a >> b;
	cout << "dljfh\n";
	return;
	int df = b - a + 1;

	//dbg(df);
	for (;; df--) {
		int l = a / df + (a % df != 0);
		int x = l * df, y = x + df;
		if (a <= x and y <= b) {
			cout << df << '\n';
			return;
		}
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