#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
int inversion(vector<int> &v) {
	int rs = 0;
	o_set<int> se;
	int j = 0;
	for (auto i : v) {
		rs += 1ll * (j - se.order_of_key(i));
		se.insert(i);
		j++;
	}
	return rs % 2;
}
void solve() {
	int n;
	cin >> n;

	vector<int> a(n), b(n);

	for (auto i : {0, 1})
		for (auto& j : (!i ? a : b)) cin >> j;

	vector<int> c = a, d = b;
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());

	cout << ((c == d and inversion(a) == inversion(b)) ? "Yes" : "No") << '\n';

	return;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}