#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

void solve() {

	int a[3];
	string s;
	cin >> a[0] >> a[1] >> a[2] >> s;


	int res = 101;
	for (auto i : {0, 1, 2}) {
		if (s == "Red" and i != 0) res = min(res, a[i]);
		if (s == "Green" and i != 1) res = min(res, a[i]);
		if (s == "Blue" and i != 2) res = min(res, a[i]);
	}

	cout << res << '\n';

}
/*

*/
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}