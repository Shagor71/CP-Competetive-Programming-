
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
const int N = 2e5 + 7, MX = N, M = 998244353;

vector<ll> a(N);
map<pair<int, ll>, ll> dp;
int n;

ll combine(ll x, ll y) {
	return x | y;
}
struct Sparse_Table {
	ll st[35][N], lg[N];
	int n;

	void LG() {
		lg[0] = lg[1] = 0;
		for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
		return;
	}
	void clear(int n) {
		for (int i = 0; i < 30 ; ++i)
			for (int j = 0; j < n; ++j) st[i][j] = 0;
		this->n = n;
	}
	void build(vector<ll> &a) {
		n = a.size();
		clear(n);
		LG();
		for (int i = 0; i < n; ++i) st[0][i] = a[i];
		for (int i = 1; (1 << i) <= n; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = combine(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		return;
	}
	ll query(int l, int r) {// index -> 0
		int i = lg[r - l + 1];
		return combine(st[i][l], st[i][r - (1 << i) + 1]);
	}
} SPT;

pair<int, ll> pos(int lo, int hi, ll cur) {
	int i = hi;
	ll val = cur;
	while (lo <= hi) {
		int m = lo + hi >> 1;
		ll tmp = SPT.query(lo, m);
		tmp >= cur ? (val = max(val, tmp), i = min(i, m), hi = m - 1) : lo = m + 1;
	}
	return {i, val};
}

ll cal(int i, ll now) {
	if (i >= n) return 1ll;
	if (dp.find(mk(i, now)) != dp.end()) return dp[mk(i, now)];
	ll &res = dp[mk(i, now)];
	ll x = cal(i + 1, now | a[i]);
	dbg(i, i + 1, now);
	pair<int, ll> j = pos(i, n - 1, 0);
	ll y = (j.second >= now ? cal(j.first + 1, j.second) : 0ll);
	dbg(i, j.first, now);
	return res = x + y % M;
}
void solve() {

	cin >> n;

	vector<ll> a(n);
	for (auto &i : a) cin >> i;
	SPT.build(a);

	cout << cal(0, 0ll) << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}