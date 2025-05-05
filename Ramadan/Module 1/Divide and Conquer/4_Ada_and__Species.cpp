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
	for (int i = 0; i < 4; ++i)
		if (a[i] <= b[i]) return 0;
	return 1;
}
void solve() {

	int n; cin >> n;

	vector<array<int, 4>> a(n);
	for (auto& i : a)
		for (int j = 0; j < 4; ++j) cin >> i[j];

	sort(a.begin(), a.end(), comp);
	for (auto i : a) {
		for (auto j : i) cout << j << ' ';
		cout << '\n';
	}
	/*int k = 0, res = 0;
	for (auto i : a) {
		int kk = 0, ok = 0;
		for (auto ii : a) {
			if (k == kk) continue;
			ok |= okk(i, ii);
			kk++;
		}
		k++;
		res += ok;
		//for (int j = 0; j < 4; ++j) cout << i[j] << " \n"[j == 3];
	}
	cout << n - res << '\n';*/

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}