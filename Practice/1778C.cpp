#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 2e5 + 7, M = 998244353;

int f(int p) {
	return p * (p + 1) >> 1;
}
void solve() {

	int n, k;
	string a, b;
	cin >> n >> k >> a >> b;

	string se = "";
	for (int i = 0; i < n; ++i) if (a[i] != b[i]) se += a[i];
	sort(se.begin(), se.end());

	se.resize(distance(se.begin(), unique(se.begin(), se.end())));

	dbg(se);

	if (se.size() <= k) {
		cout << f(n) << '\n';
		return;
	}

	vector<int> bt(se.size(), 0);
	for (int i = 0; i < k; ++i) bt[i] = 1;

	sort(bt.begin(), bt.end());

	auto cal = [&]() {
		dbg(bt);
		auto ok = [&](char c) {
			for (int i = 0; i < se.size(); ++i)
				if (bt[i] and se[i] == c) return 1;
			return 0;
		};

		int pair = 0, i = 0;

		while (i < n) {
			int l = 0, j = i;
			while (i < n and (a[i] == b[i] or ok(a[i]))) l++, i++;
			i++;
			pair += f(l);
		}
		return pair;
	};

	int res = 0;

	do {
		res = max(res, cal());
	} while (next_permutation(bt.begin(), bt.end()));

	cout << res << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}