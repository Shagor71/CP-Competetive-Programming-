#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define  int long long
const int N = 1e5 + 7, INF = -1e9, M = 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto&it : a) cin >> it;
	string s;
	cin >> s;
	int zero = 0, one = 0, i = 0, pre[n + 10];
	pre[0] = 0;
	for (auto it : s) {
		it == '1' ? one ^= a[i] : zero ^= a[i];
		i++;
		pre[i] = pre[i - 1] ^ a[i - 1];
	}
	int q;
	cin >> q;
	while (q--) {
		int tp, x, y;
		cin >> tp >> x;
		if (tp == 1) {
			cin >> y;
			zero ^= (pre[y] ^ pre[x - 1]);
			one ^= (pre[y] ^ pre[x - 1]);
		}
		else
			cout << (x ? one : zero) << ' ';
	}
	cout << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}