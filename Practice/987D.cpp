#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
const int N = 1e5 + 7;

int e;

void solve() {

	int n; cin >> n;

	vector<int> a(n + 1);
	set<pair<int, int>> se, se0;

	vector<int> boro(n + 1), res(n + 1), choto(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		se.insert({a[i], i});
		se0.insert({a[i], i});
		boro[i] = i;
		choto[i] = i;
		res[i] = a[i];
	}

	for (int i = n; i; --i) {
		if (se.size()) {
			auto tmp = se.lower_bound({a[i], i});
			if (tmp != se.end() and tmp->first == a[i] and tmp->second == i) se.erase(tmp);
		}
		while (se.size() and se.rbegin()->first > a[i]) {
			choto[prev(se.end())->second] = i;
			se.erase(prev(se.end()));
		}
	}

	for (int i = n; i; --i) {
		if (se0.rbegin()->first > a[i]) boro[i] = se0.rbegin()->second;
		se0.erase(se0.lower_bound({a[i], i}));
		res[i] = max({res[i], a[boro[i]], res[choto[boro[i]]]});
	}

	/*dbg(choto)
	dbg(boro)
	dbg(res)*/
	for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i == n];
}
/*
2 4 1 6 3 8 5 7

boro x choto

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}