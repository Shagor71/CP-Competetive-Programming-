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

struct st {
	int tw, fv;
};
st cal(int n) {
	int cnt2 = 0, cnt5 = 0, two = 2, five = 5;
	while (five <= n) {
		cnt5 += n / five;
		five *= 5;
	}
	while (two <= n) {
		cnt2 += n / two;
		two *= 2;
	}
	return {cnt2, cnt5};
}
st cal(int p, int q) {
	int cnt2 = 0, cnt5 = 0;
	while (p % 2 == 0) p /= 2, cnt2++;
	while (p % 5 == 0) p /= 5, cnt5++;
	return {cnt2 * q, cnt5 * q};
}
void solve() {

	int n, r, p, q;
	cin >> n >> r >> p >> q;

	st nn = cal(n), nr = cal(n - r), rr = cal(r);
	st res0 = {nn.tw - (nr.tw + rr.tw), nn.fv - (nr.fv + rr.fv)};
	st res1 = cal(p, q);

	cout << "Case " << ++e << ": " <<  min(res0.tw + res1.tw , res0.fv + res1.fv) << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}