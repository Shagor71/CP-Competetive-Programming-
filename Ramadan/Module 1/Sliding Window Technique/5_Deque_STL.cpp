#include <bits/stdc++.h>
using namespace std;

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

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	multiset<int> se;
	for (int i = 0, j = 0; i < n; ++i) {
		cin >> a[i];
		se.insert(a[i]);
		if (i >= k - 1) {
			cout << *se.rbegin() << ' ';
			se.erase(se.find(a[j++]));
		}
	}
	cout << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}