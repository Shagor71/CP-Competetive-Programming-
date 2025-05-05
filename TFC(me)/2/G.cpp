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
const int N = 1e5 + 5, M = 1e9 + 7;

int e;

void solve() {

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int sum = 0;
	for (int i = 0; i < n; ++i) sum += abs(a[i] - b[i]);
	cout << "Case " << ++e << ": " << sum << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}