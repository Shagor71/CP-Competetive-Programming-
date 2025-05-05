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

#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n; cin >> n;

	vector<int> res;
	res.push_back(0);
	for (int i = 1, k = 0; i < (n << 1); ++i) {
		vector<int> tmp;
		if (i <= n) {
			for (int j = 0, x; j < i; ++j) {
				cin >> x;
				if (!j) tmp.push_back(res.front() + x);
				else if (j + 1 == i) tmp.push_back(res.back() + x);
				else
					tmp.push_back(max(res[j - 1], res[j]) + x);
			}
		}
		else {
			k++;
			for (int j = 0, x; j < n - k; ++j) {
				cin >> x;
				tmp.push_back(max(res[j], res[j + 1]) + x);
			}
		}
		dbg(tmp);
		res.clear();
		res = tmp;
	}

	cout << "Case " << ++e << ": " << *max_element(res.begin(), res.end()) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}