#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e3 + 7;

struct st {
	int sum, cnt;
};
st combine(st tmp, int ext, int m) {
	return {tmp.sum + tmp.sum + m * tmp.cnt + (ext * m), (tmp.cnt << 1) + ext};
}
st cal(int n, int k) {
	if (n < k) return {0, 0};
	int m = n + 1 >> 1;
	int ext = n % 2;
	st tmp = cal(m - ext, k);
	dbg(n, m, tmp.cnt, tmp.sum);
	return combine(tmp, ext, m);
}
void solve() {
	int n, k;
	cin >> n >> k;

	/*if (k == 1) {
		cout << n*(n + 1) / 2 << '\n';
		return;
	}*/
	cout << cal(n, k).sum << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}