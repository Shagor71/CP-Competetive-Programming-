#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n, m, c;
	cin >> n >> m >> c;

	vector<int> a(n), b(n, 0);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		b[i] += i ? b[i - 1] : 0;
		b[i] %= c;
	}
	for (int i = m; i < n; ++i) b[i] = b[i - 1];

	for (int i = 0; i < n; ++i) {
		int res = (a[i] + b[i]) % c;
		int j = i - (n - m) - 1;
		res -= j < 0 ? 0 : b[j];
		res += c;
		cout << res % c << " \n"[i == n - 1];
	}
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}