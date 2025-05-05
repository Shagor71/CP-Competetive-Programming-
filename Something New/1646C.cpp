#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	set<tuple<int, int, int>> se;
	se.insert({2, 4, 1});
	se.insert({2, 3, 1});
	se.insert({2, 3, 2});

	for (auto [a, b, c] : se) cout << a << ' ' << b << ' ' << c << '\n';

}
/*
	241 - 128 = 113 - 64 = 49 - 32 = 17 - 16 = 1
	241 - 120 =

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}