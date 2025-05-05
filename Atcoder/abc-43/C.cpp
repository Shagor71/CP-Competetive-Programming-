#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

const int N = 1e6 + 5, mod = 1e9 + 7;

int cal(int y, vector<int>&a) {
	int sum = 0;
	for (auto x : a)
		sum += (x - y) * (x - y);
	return sum;
}
int ternary(vector<int>&a, int lo, int hi) {
	int res = N;
	while (lo <= hi) {
		int m1 = lo + (hi - lo) / 3;
		int m2 = hi - (hi - lo) / 3;
		int f1 = cal(m1, a), f2 = cal(m2, a);
		//dbg(m1, m2, f1, f2, res)
		if (f1 < f2) {
			res = min(res, f1);
			hi = m2 - 1;
		}
		else {
			res = min(res, f2);
			lo = m1 + 1;
		}
	}
	return res;
}
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	cout << ternary(a, -100, 100) << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}