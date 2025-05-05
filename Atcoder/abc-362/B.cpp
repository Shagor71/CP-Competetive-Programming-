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
	int x, y;
};
void solve() {

	vector<st> c(3);
	for (auto& i : c) cin >> i.x >> i.y;


	vector<int> a;
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 3; ++j) {
			int x = c[i].x - c[j].x, y = c[i].y - c[j].y;
			a.push_back(x * x + y * y);
		}
	}
	sort(a.begin(), a.end());

	cout << (a.back() == a[0] + a[1] ? "Yes" : "No") << '\n';


}
/*

*/
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}