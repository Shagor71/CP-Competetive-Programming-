#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*#define _42_
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
	int k;
	cin >> s >> k;

	set<string> se;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j + i <= s.size(); ++j) {
			string sub = s.substr(j, i);
			se.insert(sub);
		}
	}

	for (auto i : se) {
		if (k == 1) {
			cout << i << '\n';
			return;
		}
		k--;
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