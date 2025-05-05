#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e3 + 7, M = 998244353;

void solve() {
	string s;
	int k;
	cin >> s >> k;

	if (k <= s.size()) {
		cout << s[k - 1];
		return;
	}

	stack<char> st;
	int bad = 0, sum = s.size();
	for (int i = 0; i < s.size(); ++i) {
		while (!st.empty() and st.top() > s[i]) {
			bad++;
			st.pop();
			if (sum + s.size() - bad >= k) {
				int ext = k - sum;
				if (ext <= st.size()) {
					while (st.size() > ext) st.pop();
					cout << st.top();
					return;
				}
				cout << s[i + ext - st.size() - 1];
				return;
			}
			sum += s.size() - bad;
		}
		st.push(s[i]);
	}
	while (sum + s.size() - bad - 1 < k) bad++, sum += s.size() - bad;
	dbg(sum, k);
	int ext = k - sum;
	while (st.size() > ext) st.pop();
	cout << st.top();
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}