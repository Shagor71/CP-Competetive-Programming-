#include <bits/stdc++.h>
using namespace std;
/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e5 + 5, M = 1e9 + 7;


map<int, int> m;
void solve() {

	int n; cin >> n;

	std::vector<int> a(n);
	for (auto& i : a) cin >> i, m[i]++;
	sort(a.rbegin(), a.rend());

	int res = 0;
	for (auto i : a) {
		for (int j = 31; (1ll << j) > i; j--) {
			int x = (1ll << j) - i;
			if (x == i and m[i] < 2) continue;
			if (m[x] and m[i]) {
				res++;
				m[i]--;
				m[x]--;
				break;
			}
		}
	}
	cout << res << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}