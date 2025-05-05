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

	vector<int> a(n), prf(n), suf(n);
	int k = 0;
	for (auto &i : a) {
		cin >> i;
		prf[k] = suf[k] = k;
		k++;
	}

	stack <pair<int, int>> p_st, s_st;
	for (int i = 0, j = n - 1; i < n; ++i, j--) {
		while (!p_st.empty() and p_st.top().first >= a[i])
			prf[i] = prf[p_st.top().second], p_st.pop();
		p_st.push({a[i], i});
		while (!s_st.empty() and a[j] <= s_st.top().first)
			suf[j] = suf[s_st.top().second], s_st.pop();
		s_st.push({a[j], j});
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, a[i] * (i - prf[i] + 1 + suf[i] - i));
	}
	dbg(prf, suf);

	cout << "Case " << ++e << ": " << res << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}