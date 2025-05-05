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

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	int sum = 0, r, mx = MX;
	for (int i = 0, j = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		if (i >= k - 1) {
			if (sum < mx) mx = sum, r = i;
			sum -= a[j++];
		}
	}
	//cout << r << '\n';
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		if (r - k < i and i <= r) continue;
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());

	int res = 2 * accumulate(v.begin(), v.begin() + ((v.size() + 1) >> 1), 0ll);

	cout << res - (v.size() % 2 ? v[v.size() / 2] : 0) << '\n';
}
/*
8 4
1 1 1 5 3 2 2 1
8 4
1 2 2 3 5 1 1 1
1 1 1 5 3 2 2 1
8 4
1 2 2 3 5 1 1 1

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}