#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e5 + 5, M = 1e9 + 7;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second >= b.second;
}
void solve() {

	int n; cin >> n;

	int x = 0, z = 0;
	vector<pair<int, int>> y;

	while (n--) {
		string s;
		cin >> s;

		stack<char> st;
		int xx = 0, yy = 0;
		for (auto i : s) {
			if (!st.empty() and st.top() == '(' and i == ')' ) st.pop(), xx--;
			else st.push(i), i == '(' ? xx++ : yy--;
		}
		if (!xx or !yy) x += xx, z += yy;
		else y.push_back({yy, xx});
	}

	if (y.empty()) {
		//dbg(x, z);
		cout << ((x + z) ? "No\n" : "Yes\n");
		return;
	}
	if (!x or !z) {
		cout << "No\n";
		return;
	}

	sort(y.rbegin(), y.rend());

	int nx = x;
	bool ok = 1;
	for (auto i : y) {
		if (nx + i.first < 0) {
			ok = 0;
			break;
		}
		nx += i.first + i.second;
	}
	if (ok and nx + z == 0) {
		cout << "Yes\n";
		return;
	}

	sort(y.begin(), y.end(), comp);
	for (auto i : y) {
		if (x + i.first < 0) {
			cout << "No\n";
			return;
		}
		x += i.first + i.second;
	}
	cout << ((x + z) ? "No\n" : "Yes\n");
	//dbg(y);
}
/*

	{-1, 4}, (-2, 5);
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}