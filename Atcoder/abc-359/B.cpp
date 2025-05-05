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

	int n;
	cin >> n;

	vector<int> a(n << 1);
	int res = 0;
	for (int i = 0; i < n << 1; ++i) {
		cin >> a[i];
		res += (1 < i and a[i - 2] == a[i]);
	}
	cout << res << '\n';

}
/*
	l m r

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}