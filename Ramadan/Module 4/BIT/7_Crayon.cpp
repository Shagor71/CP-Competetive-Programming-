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
int n;
struct node {
	int sum = 0, cnt = 0;
};
struct BIT {
	node t[N];
	int lsb(int x) {
		return x & -x;
	}
	int query(int pos) {
		int res = 0;
		for (; pos; pos -= lsb(pos))
			res += t[pos].cnt;
		return res;
	}
	void update(int pos, int val) {
		int res = 0;
		for (; pos <= n; pos += lsb(pos)) {
			t[pos].sum += val;
			t[pos].cnt += val <= 1;
		}
		for (int i = 1; i <= n; i++) cout << t[i].sum << ' ';
		cout << '\n';
	}
} bit;
void solve() {

	int q;
	cin >> q;

	vector<pair<char, pair<int, int>>> p(q);
	map<int, int> m;
	for (auto& [f, s] : p) {
		cin >> f >> s.first;
		m[s.first] = 0;
		if (f != 'C') {
			cin >> s.second;
			m[s.second] = 0;
		}
	}
	int j = 0;
	for (auto [x, i] : m) m[x] = ++j;
	n = j;

	vector<pair<int, int>> D;
	for (auto [f, s] : p) {
		if (f == 'D') {
			D.push_back(s);
			bit.update(m[s.first], 1);
			bit.update(m[s.second] + 1, -1);
			continue;
		}
		if (f == 'Q') cout << bit.query(m[s.second]) - bit.query(m[s.first - 1]) << '\n';
		else {
			bit.update(m[D[s.first - 1].first], -1);
			bit.update(m[D[s.first - 1].second] + 1, 1);
		}
	}
}
/*
	1  2  3  4  5
	1       -1


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}