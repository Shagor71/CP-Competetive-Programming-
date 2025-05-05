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

	int n, k;
	cin >> n >> k;

	vector<char> res;
	for (char c = 'A'; c - 'A'  < n ; ++c)
		res.push_back(c);

	cout << "Case " << ++e << ":\n";
	do {
		for (auto  c : res) cout << c;
		cout << '\n';
		k--;
		if (!k) return;
	}
	while (next_permutation(res.begin(), res.end()));
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}