#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

int f(vector<int>&a) {
	return (a[0] > a[2] and a[1] > a[3]) + (a[0] > a[3] and a[1] > a[2]);
}
void solve() {

	vector<int> a(4);
	for (auto& i : a) cin >> i;

	int res = f(a), t = 4;
	swap(a[0], a[1]);
	res += f(a);

	cout << res << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}