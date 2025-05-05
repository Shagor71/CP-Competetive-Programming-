#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
//#define int long long int
#define mk make_pair
const int N = 2e5 + 1, M = 1e7 + 7;

bool cmp(pair<int, int>&a, pair<int, int>&b) {
	return a.second <= b.second;
}
void solve() {

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> a(n);
	int j = 0;
	for (auto& i : a) cin >> i.first, i = {i.first + j, j++};
	sort(a.rbegin(), a.rend());

	j = 0;
	while (k--) a[j++].first = 0;

	sort(a.begin(), a.end(), cmp);
	dbg(a)
	j = 0;
	int res = 0, zero = 0;
	for (auto i : a) {
		i.first ? res += (i.first - j) + zero : zero++;
		j++;
	}

	cout << res << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc; while (tc--)
		solve();
}