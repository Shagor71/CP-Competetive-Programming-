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

void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	map<int, deque<int>> pos;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pos[a[i]].push_back(i + 1);
	}

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		pos[a[i]].pop_front();
		v[i] = pos[a[i]].empty() ? n + 1 : pos[a[i]].front();
		cout << v[i] << ' ';
	}

	o_set<int> se;
	for (int i = 0; i < n; ++i) {
		se.insert(v[i]);

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