#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

map<int, int> f;

void solve() {

	int n, k, q;
	cin >> n >> k >> q;

	vector<int> a(n + 1), res(n + 1);

	set<pair<int, int>> se;
	f.clear();

	for (int i = 1; i <= n; ++i) {
		cin >> a[i], a[i] -= i;
		//cout << a[i] << ' ';
		f[a[i]]++;
		se.insert({f[a[i]], a[i]});
		if (i >= k) {
			res[i] = k - se.rbegin()->first;
			se.erase(se.find({f[a[i - k + 1]], a[i - k + 1]}));
			f[a[i - k + 1]]--;
		}
	}
	//cout << '\n';
	while (q--) {
		int l, r;
		cin >> l >> r;

		cout << res[r] << '\n';
	}
}
/*
	l m r
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}