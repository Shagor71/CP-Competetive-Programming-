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
const int N = 2e5 + 7, MX = 1e9 + 37, M = 1e9 + 7;
int e;

void solve() {

	int n; cin >> n;

	vector < pair<int, pair<int, int>>> p(n);
	int j = 0, fs = MX;
	for (auto &x : p) {
		cin >> x.first >> x.second.first;
		x.second.first++;
		x.second.second = ++j;
		fs = min({fs, x.first, x.second.first});
	}
	int tmp = p.front().first;

	sort(p.begin(), p.end());
	dbg(p);
	int rt = p.front().first, res = 0;
	j = 0;
	for (auto x : p) {
		if (j and p[j - 1].first <= x.first and x.second.first <= p[j - 1].second.first) res = x.second.second;
		if (j and x.first <= p[j - 1].first and p[j - 1].second.first <= x.second.first) res = p[j - 1].second.second;
		rt = max(rt, x.second.first);
		j++;
	}

	if (res) {
		cout << res << '\n';
		return;
	}
	vector<int> mn(n + 2), mx(n + 2);
	for (int i = 0, j = n - 1; i < n; ++i, --j) {
		mx[i] = max(i ? mx[i - 1] : fs, p[i].second.first);
		mn[j] = min(i ? mn[j + 1] : rt,  p[j].first);
	}

	for (int j = 1; j < n - 1; ++j)
		if (p[j].first <= mx[j - 1] and mn[j + 1] <= p[j].second.first and mn[j + 1] <= mx[j - 1]) {
			cout << p[j].second.second << '\n';
			return;
		}

	cout << "-1\n";
}
/*
3
1 3
2 5
5 6

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}