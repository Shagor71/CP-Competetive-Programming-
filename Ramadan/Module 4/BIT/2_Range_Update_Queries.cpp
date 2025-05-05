#include <bits/stdc++.h>
using namespace std;

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
int n;
struct BIT {
	int t[N];
	int lsb(int x) {
		return x & -x;
	}
	void update(int pos, int val) {
		for (; pos <= n; pos += lsb(pos)) t[pos] += val;
	}
	int query(int pos) {
		int res = 0;
		for (pos; pos > 0; pos -= lsb(pos)) res += t[pos];
		return res;
	}
} bit;

void solve() {

	int q;
	cin >> n >> q;

	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		bit.update(i, x);
		bit.update(i + 1, -x);
	}

	while (q--) {
		int t; cin >> t;
		if (t == 2) {
			int x; cin >> x;
			cout << bit.query(x) << '\n';
			continue;
		}
		int l, r, x;
		cin >> l >> r >> x;
		bit.update(l, x);
		bit.update(r + 1, -x);
	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}