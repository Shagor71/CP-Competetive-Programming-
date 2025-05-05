#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e3 + 5, M = 1e9 + 7;

int dp[105][100005];
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());
	int sum = accumulate(a.begin(), a.end(), 0ll);

	for (int i = 0; i <= n; ++i) dp[i][0] = 1;
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= sum; ++i) {
			if (i >= a[j - 1])
				dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - a[j - 1]]);
			else dp[j][i] = dp[j - 1][i];
		}
	}

	vector<int> res;
	for (int i = 1; i <= sum; ++i) {
		if (dp[n][i]) res.push_back(i);
	}
	cout << res.size() << '\n';
	for (auto& i : res) cout << i << ' ';



}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}