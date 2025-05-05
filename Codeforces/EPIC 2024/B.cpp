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

	int n;
	cin >> n;

	deque<int> a(n), b(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;

	while (a.size() > 1) {
		if (a.front() != b.front() and a.front() != b.back()) {
			cout << "Alice\n";
			return;
		}
		else if (a.back() != b.front() and a.back() != b.back()) {
			cout << "Alice\n";
			return;
		}
		else {
			if (a.front() == b.front() or a.front() == b.back()) {
				a.front() == b.front() ? b.pop_front() : b.pop_back();
				a.pop_front();
			}
			else {
				a.back() == b.front() ? b.pop_front() : b.pop_back();
				a.pop_back();
			}
		}
	}

	cout << (a.front() == b.front() ? "Bob" : "Alice") << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}