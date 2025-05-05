#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e5 + 5, M = 1e9 + 7;

int e;

bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.first < a.second;
}
void solve() {

	int q;  cin >> q;

	vector<pair<int, int>> m;
	bool ok = 0;
	int x = 0;
	while (q--) {
		string s;
		cin >> s;
		stack<int> st;
		for (auto i : s) {
			if (!st.empty() and i == ')') st.pop();
			else st.push(i);
		}
		string a = "";
		while (!st.empty())
			a = st.top() + a, st.pop();

		if (a.front() != a.back()) {
			int aa = 0, bb = 0;
			for (auto i : a) i == ')' ? bb-- ; aa++;
			m.push_back({bb, aa});
		}
		else
			a.front() == '(' ? x += a.size() : x -= a.size();
	}

	if (x == 0) {
		cout << (m.empty() ? "Yes" : "No") << '\n';
		return;
	}

	if (x > 0) {
		sort(m.rbegin(), m.rend(), comp);
		for (auto i : a) {
			if (x < i.first)  {
				cout << "No\n";
				return;
			}
			x -= i.first;
			x += i.second;
		}
		cout << (x ? "No" : "Yes") << '\n';
		return;
	}

	sort(m.begin(), m.end());
	for (auto i : a) {
		if (x < i.first)  {
			cout << "No\n";
			return;
		}
		x -= i.first;
		x += i.second;
	}
	cout << (x ? "No" : "Yes") << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}