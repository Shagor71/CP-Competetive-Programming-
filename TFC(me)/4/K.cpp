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
//#define int long long
#define mk make_pair
const int N = 1e3 + 5, M = 1e6 + 7;

map<int, int> m;
void solve() {

	int n; cin >> n;

	vector<int> a(n + 1, 0);
	int res = 0;
	m[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int x = a[i];
		a[i] = (a[i - 1] + a[i]) % n;
		res += m[(n + a[i]) % n];
		m[(n + a[i]) % n]++;
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