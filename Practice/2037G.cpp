#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/

#define int long long
const int N = 1e6 + 7, mod = 998244353;

int e;
vector<int> prime[N], posi[N];
bool vis[N];
int cnt[N], netway[N];

void sieve() {
	for (int i = 2; i < N; ++i) {
		if (!vis[i])
			for (int j = i; j < N; j += i) prime[j].push_back(i), vis[j] = i;
	}
	return;
}
void IN_EX(vector<int> &v, int ps) {
	int sz = v.size();
	vector<int> val;
	for (int msk = 1; msk < (1 << sz); ++msk) {
		int x = 1, cn = 0;
		for (int i = 0; i < sz; ++i) if (msk & (1 << i)) x *= v[i], cn++;
		val.push_back(x);
		int way = ps ? cnt[x] : 1;
		netway[ps] = (netway[ps] + (cn & 1 ? 1 : -1) * way) % mod;
	}
	for (auto x : val) cnt[x] = (cnt[x] + netway[ps]) % mod;
	return;
}
void solve() {

	int n; cin >> n;

	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		IN_EX(prime[x], i);
	}

	cout << (mod + netway[n - 1]) % mod << '\n';
}
/*
2 4 1 6 3 8 5 7

boro x choto

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	sieve();
	solve();
}