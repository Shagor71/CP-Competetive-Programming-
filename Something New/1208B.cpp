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

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

map<int, bool> ml, mr;
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto &i : a) cin >> i;

	if (n == 1) {
		cout << "0\n";
		return;
	}

	int l, r, len = 1  	, res = 1;
	for (l = 0; l < n; ++l) {
		if (ml[a[l]]) {
			l--;
			break;
		}
		res = len = l + 1;
		ml[a[l]] = 1;
	}
	dbg(res);
	for (r = n - 1; 0 <= l and l < r; r--) {
		if (mr[a[r]]) break;
		while (0 <= l and ml[a[r]]) ml[a[l]] = 0, l--, len--;
		len++;
		dbg(l, r, len, res);
		res = max(res, len);
		mr[a[r]] = 1;
	}
	while (l <= r and !mr[a[r]] and !ml[a[r]]) {
		len++;
		res = max(res, len);
		r--;
	}
	cout << n - res << '\n';

}
/*
	241 - 128 = 113 - 64 = 49 - 32 = 17 - 16 = 1
	241 - 120 =

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}