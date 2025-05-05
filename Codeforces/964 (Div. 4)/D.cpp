#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

void solve() {

	string a, b;
	cin >> a >> b;

	string s = "";
	while (!a.empty() and !b.empty()) {
		if (a.front() == '?' or a.front() == b.front()) {
			s += b.front();
			b.erase(b.begin());
		}
		else s += a.front();
		a.erase(a.begin());
	}

	if (b.empty()) {
		cout << "Yes\n" << s;
		while (!a.empty()) {
			cout << (a.front() == '?' ? 'a' : a.front());
			a.erase(a.begin());
		}
		cout << '\n';
	}
	else cout << "No\n";
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}