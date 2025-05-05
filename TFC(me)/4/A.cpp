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
#define int long long int
#define mk make_pair
const int N = 1e6 + 5, M = 1e6 + 7;

void solve() {

	int n; cin >> n;
	cout << n << endl;
	return;
	vector<int> a(10);
	a[0] = n + 1;
	for (int i = 1; i <= 9; ++i) cin >> a[i];
	int mn = *min_element(a.begin(), a.end()), sz = n / mn;

	string res = "";
	for (int l = 1; l <= sz; ++l) {
		char c = '9';
		for (int i = 9; i; i--, c--) {
			if (n - a[i] >= mn * (sz - l)) {
				res += c;
				n -= a[i];
				break;
			}
		}
	}

	cout << res << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}