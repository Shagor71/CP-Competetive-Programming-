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

int mn[N];

void solve() {

	int n, k;
	cin >> n >> k;

	int x, a, b, c;
	cin >> x >> a >> b >> c;

	vector<int> v(n);
	deque<int> dq;
	ll res = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		v[i] = i ? (1LL * a * v[i - 1] + b) % c : x % c;
		if (!dq.empty() and dq.front() == i - k) dq.pop_front();
		while (!dq.empty() and v[dq.back()] >= v[i]) dq.pop_back();
		dq.push_back(i);
		if (i >= k - 1)
			res ^= v[dq.front()];
	}

	cout << res << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}