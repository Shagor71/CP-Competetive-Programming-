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

bool comp(array<int, 4>&a, array<int, 4>&b) {
	return a[1] <= b[1];
}
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int q; cin >> q;
	vector<array<int, 4>> p(q), _p;
	int j = 0;
	for (auto& i : p) {
		cin >> i[0] >> i[1] >> i[2];
		i[0]--, i[1]--;
		i[3] = j++;
		_p.push_back({i[1], i[0], i[2], i[3]});
	}
	sort(p.begin(), p.end());

	vector<int> res(q);
	o_set<pair<int, int>> se;
	for (int i = 0, j = 0; i < n and j < q; ++i) {
		while (j < q and i == p[j][0]) {
			int pos = se.order_of_key({p[j][2], i});
			res[p[j][3]] = (int)se.size() - pos;
			j++;
		}
		se.insert({a[i], i});
	}

	se.clear();
	sort(_p.begin(), _p.end());
	for (int i = 0, j = 0; i < n and j < q; ++i) {
		se.insert({a[i], i});
		while (j < q and i == _p[j][0]) {
			int pos = se.order_of_key({_p[j][2], i});
			res[_p[j][3]] = (int)se.size() - pos - res[_p[j][3]];
			j++;
		}
	}

	for (auto i : res) cout << i << '\n';
}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}