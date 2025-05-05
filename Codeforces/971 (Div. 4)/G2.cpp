#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 2e5 + 7;

map<int, int> f;
void solve() {
	int n, k, q;
	cin >> n/* >> k >> q*/;

	vector<int> a(n + 1), cost(n + 1);

	//dbg(cost);
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i) dp[i] = i, cin >> cost[i];

	stack<pair<int, int>> st;
	for (int i = n; i; --i) {
		while (!st.empty() and st.top().first >= cost[i])
			dp[i] = max(dp[i], dp[st.top().second]), st.pop();
		st.push({cost[i], i});
	}
	//dbg(dp);

	/*while (q--) {
		int l, r;
		cin >> l >> r;
	}*/
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}
