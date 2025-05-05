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
#define int long long int
#define mk make_pair
const int N = 1e5 + 5, M = 1e9 + 7;

int cnt1, cnt2;
map <int, bool> m;
void cal(int n) {
	for (int i = 2; i * i * i <= n; ++i) {
		int tmp = i * i;
		while (tmp <= n / i) {
			tmp *= i;
			if (m[tmp]) continue;
			int sq = sqrtl(tmp);
			if (sq * sq == tmp) cnt1++;
			m[tmp] = true, cnt2++;
		}
	}
	return;
}
void solve() {

	int n; cin >> n;
	cal(n);
	int sq = sqrtl(n);
	cout << sq + cnt2 - cnt1 << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}