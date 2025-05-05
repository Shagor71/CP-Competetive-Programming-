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
void solve() {

	int q;
	cin >> q;
	string s;
	getline(cin, s);
	while (q--) {
		string a, b;

		getline(cin, a);
		getline(cin, b);

		vector<char> sa, sb;
		for (auto i : a) {
			sa.push_back('a' <= i and i <= 'z' ? i : (char)(i + 32));
		}
		for (auto i : b) {
			sb.push_back('a' <= i and i <= 'z' ? i : (char)(i + 32));
		}
		sort(sa.begin(), sa.end());
		sort(sb.begin(), sb.end());
		while (sa.front() == '@') sa.erase(sa.begin());
		while (sb.front() == '@') sb.erase(sb.begin());
		//for (auto i : sa) cout << i; cout << '\n';
		//for (auto i : sb) cout << i; cout << '\n';
		cout << "Case " << ++e << ": " << (sa == sb ? "Yes" : "No") << '\n';
	}
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}