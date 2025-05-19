#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

	int n, k;
	cin >> n >> k;

	multiset<int> se;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		se.insert(x);
	}

	if (*se.rbegin() - *se.begin() > k) {
		int x = *se.rbegin() - 1;
		se.erase(--se.end());
		se.insert(x);
		if (*se.rbegin() - *se.begin() > k) {
			cout << "Jerry\n";
			return;
		}
		int sum = 0;
		for (auto i : se) sum += i;
		cout << (sum & 1 ? "Jerry" : "Tom") << '\n';
		return;
	}
	int sum = 0;
	for (auto i : se) sum += i;

	cout << (sum & 1 ? "Tom" : "Jerry") << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}