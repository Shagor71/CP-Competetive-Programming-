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
int dp[N];

int cal(int n) {
	//when alice first
	if (n <= 2) return n != 1;
	//when bob first
	if (n <= 2) return 1;
	int &res = dp[n];
	if (~res) return res;
	res = 0;
	for (auto i : {1, 2}) res ^= cal(n - i);
	return res;
}
void solve() {

	int n;
	string c;
	cin >> n >> c;

	//memset(dp, -1, sizeof dp);
	//cal(n);
	//for (int i = 1; i <= n; ++i) if (!dp[i]) cout << i << ' ';

	cout << "Case " << ++e << ": ";
	if (c == "Bob") {
		cout << (n % 3 ? "Bob" : "Alice") << '\n';
	}
	else {
		int four = 4;
		while (four <= n) four *= 4;
		n -= four;
		cout << (n % 3 ? "Alice" : "Bob") << '\n';
	}
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}