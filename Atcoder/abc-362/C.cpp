#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

struct st {
	int x, y, pos;
};
bool comp(st& a, st& b) {
	return a.x <= b.x;
}
void solve() {

	int n;
	cin >> n;

	vector<st> p(n);
	int j = 0;
	for (auto& i : p) cin >> i.x >> i.y, i.pos = ++j;
	sort(p.begin(), p.end(), comp);

	for (auto i : p) cout << i.x << ' ' << i.y << '\n';

}
/*

*/
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}