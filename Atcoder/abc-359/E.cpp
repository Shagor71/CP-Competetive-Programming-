#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

struct ST {
	int x, pos;
};
int csum[N];
void solve() {

	int n;
	cin >> n;

	vector<ST> a(n + 1, {0, 0});
	for (int i = 1; i <= n; ++i) cin >> a[i].x;

	stack<ST> st;
	for (int i = n; i; --i) {
		while (!st.empty() and st.top().x <= a[i].x) {
			a[st.top().pos].pos = i;
			st.pop();
		}
		st.push({a[i].x, i});
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res = max(res + a[i].x, csum[a[i].pos] + a[i].x * (i - a[i].pos));
		csum[i] = res;
		cout << res + 1 << ' ';
	}
}
/*
	l m r

*/
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}