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

	int n; cin >> n;

	o_set<int> se;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		se.insert(x);
	}

	vector<int> a(n), res(n);
	for (auto& i : a) cin >> i;

	for (int i = n - 1; i >= 0; --i) {
		auto it = se.find_by_order(a[i]);
		res[i] = *it;
		se.erase(it);
	}
	for (auto i : res) cout << i << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}