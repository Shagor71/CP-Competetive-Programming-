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

	int n, m;
	while (cin >> m >> n and m) {
		std::vector<int> pos(n + 2, 0);
		int sum = 0, ok = 0;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			sum += x, sum %= m;
			if (!ok and (pos[sum] or !sum)) {
				for (int j = pos[sum] + 1; j <= i + 1; ++j) cout << j << " \n"[j == i + 1];
				ok = 1;
			}
			pos[sum] = i + 1;
		}
		if (!ok) cout << "no sweets\n";
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