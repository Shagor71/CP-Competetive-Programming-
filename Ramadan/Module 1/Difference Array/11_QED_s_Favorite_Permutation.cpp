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

void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> plc(n);
	for (int i = 0, x; i < n; ++i) cin >> x, plc[x - 1] = i;

	string s;
	cin >> s;

	vector<int> rng(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		if (plc[i] != i) {
			rng[min(i, plc[i])]++;
			rng[max(i, plc[i]) + 1]--;
		}
	}

	int LR = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		rng[i] += i ? rng[i - 1] : 0;
		if (rng[i]) {
			cnt++;
			LR += (cnt > 1 and s[i - 1] == 'L' and s[i] == 'R');
			continue;
		}
		cnt = 0;
	}

	while (q--) {
		int i; cin >> i;
		i--;
		if (i and s[i - 1] == 'L' and s[i] == 'R' and rng[i - 1] and rng[i]) LR--;
		if (i != n - 1 and s[i] == 'L' and s[i + 1] == 'R' and rng[i] and rng[i + 1]) LR--;
		s[i] = s[i] == 'L' ? 'R' : 'L';
		if (i and s[i - 1] == 'L' and s[i] == 'R' and rng[i - 1] and rng[i]) LR++;
		if (i != n - 1 and s[i] == 'L' and s[i + 1] == 'R' and rng[i] and rng[i + 1]) LR++;
		cout << (LR ? "No" : "Yes") << '\n';
	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}