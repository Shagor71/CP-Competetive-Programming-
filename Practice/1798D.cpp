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

#define int long long
const int N = 2e5 + 7, M = 998244353;

void solve() {

	int n; cin >> n;

	int z = 0, mx = INT_MIN, mn = INT_MAX;
	vector<int> a(n), pos, neg;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		mx = max(mx, x), mn = min(mn, x);
		if (x == 0) z++;
		else
			x < 0 ? neg.push_back(x) : pos.push_back(x);
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());

	if (mx - mn <= mx) {
		cout << "No\n";
		return;
	}

	// Kadane's Algorithm Idea.

	int under = mx - mn, sum = 0;
	vector<int> res;

	while (z--) res.push_back(0);

	while (res.size() < n) {
		while (!pos.empty() and sum + pos.back() < under) {
			res.push_back(pos.back());
			sum += pos.back();
			pos.pop_back();
		}
		while (pos.empty() and !neg.empty()) {
			res.push_back(neg.back());
			neg.pop_back();
		}
		if (!pos.empty() and !neg.empty()) {
			while (!neg.empty() and sum + pos.back() >= under) {
				sum += neg.back();
				res.push_back(neg.back());
				neg.pop_back();
			}
		}
		int tmp = pos.size() ? pos.back() : 0ll;
		if (sum + tmp >= under) {
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
	for (auto i : res) cout << i << ' ';
	cout << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}