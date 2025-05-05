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
const int N = 2e5 + 7, M = 998244353;


int cal(int p) {
	return (p * (p + 1) / 2) * (2ll * p + 1) / 3;
}
int f(int p) {
	return p * (p + 1) / 2;
}
int Row(int n) {
	int row = 1, tmp = 1;
	while (tmp < n) tmp += ++row;
	return row;
}
void solve() {

	int n; cin >> n;

	int row = Row(n), res = 0, L = n, R = n;
	while (row) {
		res += cal(R) - cal(L - 1);
		int tL = L - f(row - 1), tR = R - f(row - 1);
		L = f(row - 2) + tL - (tL != 1), R = f(row - 2) + tR - (tR >= row);
		//dbg(tL, tR, L, R);
		row--;
	}

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