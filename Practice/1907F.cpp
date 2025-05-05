#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 1e6 + 5, M = 1e9 + 7;

int ok(vector<int>&b, int n, bool flg) {
	for (int i = 0; i < n; ++i) {
		int cnt = 0, j = i;
		while (j < n + n - 1 and (flg ? b[j] <= b[j + 1] : b[j] >= b[j + 1])) {

		} cnt++, j++;
		if (cnt >= n - 1) return i + 1;
		cnt = 0;
		i = j;
	}
	return 0;
}
void solve() {

	int n;
	cin >> n;

	vector<int> a(n), b;
	int mnpos = -1;
	for (auto& i : a) {
		cin >> i;
		//if (i < mn)
	}

	if (is_sorted(a.begin(), a.end()) or is_sorted(a.rbegin(), a.rend())) {
		cout << (a.front() > a.back()) << '\n';
		return;
	}

	b = a;
	for (auto& i : a) b.push_back(i);

	dbg(b)
	int pos = ok(b, n, 1), neg = ok(b, n, 0);
	if (pos or neg) {
		int res = n + 1;
		if (neg--)
			res = min({res, neg - n + 1, n - neg + 1});
		if (pos--) {
			res = min({res, pos, n - pos});
		}
		cout << pos << ' ' << neg << '\n';
		//dbg(res);
		return;
	}

	cout << "-1\n";
}
/*
	4 5 5 2
	2 4 5 5

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}