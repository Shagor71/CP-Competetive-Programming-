#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
const int N = 1e6 + 5, M = 1e9 + 7;

vector<pair<int, int>> ext(vector<int>&x, int n) {
	int i = 0;
	vector<pair<int, int>> a;
	dbg(x);
	while (i < 3 and x[i] < n) {
		int t = x[i + 1];
		while (t > 1) {
			t = t / x[i] + (t % x[i] != 0);
			a.push_back({x[i + 1], x[i]});
			//cout << x[i + 1] << ' ' << x[i] << '\n';
		}
		i++;
	}
	reverse(a.begin(), a.end());
	return a;
}
void solve() {

	int n;
	cin >> n;

	vector<pair<int, int>> a, b;

	vector<int> x = {n, 64, 4, 2};

	sort(x.begin(), x.end());

	a = ext(x, n);

	for (int i = 3; i < n; ++i) {
		bool ok = 1;
		for (auto it : x) if (it == i) ok = 0;

		if (ok)
			b.push_back({i, i + 1});
	}

	cout << a.size() + b.size() << '\n';
	for (auto i : b) cout << i.first << ' ' << i.second << '\n';
	for (auto i : a) cout << i.first << ' ' << i.second << '\n';
	dbg(a)
	dbg(b)
}
/*
	100000 -> 50 -> 4 -> 2

	100000/50 ~ 2000/50 ~ 40/50 ~ 1  step = 3
	50/4 ~ 13/4 ~ 4/4 ~ 1 step = 3
	4/2 ~ 2/2 ~ 1 step = 2

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}