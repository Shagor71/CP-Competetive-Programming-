#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

struct C {
	int x, y;
};
int D(C &at, C &to) {
	return (at.x - to.x) * (at.x - to.x) + (at.y - to.y) * (at.y - to.y);
}
void solve() {

	int n;
	cin >> n;

	vector<C> p(n);
	for (auto& i : p) cin >> i.x >> i.y;

	C at, to;
	cin >> at.x >> at.y >> to.x >> to.y;

	int ds = 2e18 + 7;
	for (auto i : p) {
		//cout << D(i, to) << ' ';
		ds = min(ds, D(i, to));
	}
	/*if (ds <= D(at, to))
		cout << ds << '\n' << D(at, to) << '\n';*/
	cout << (ds > D(at, to) ? "Yes" : "No") << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}