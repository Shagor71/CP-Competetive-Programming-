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

	int n, L, W;
	string s;
	cin >> n >> L >> W >> s;

	s = 'L' + s;
	int i = 0;
	while (i <= n) {
		if (s[i] == 'L') {
			int j = i + min(n, L);
			for (; j > i + 1; j--)
				if (s[j] == 'L') break;
			i = s[j] != 'L' ? i + L : j;
		}
		else if (s[i] == 'W')
			while (i <= n and s[i] == 'W') i++, W--;
		else {
			cout << "No\n";
			return;
		}
		if (W < 0) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}
/*

*/
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}