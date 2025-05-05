#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
//#define int long long
const int N = 1e6 + 9, INF = 2e9 + 7;

int side[4];

bool is_posible(vector<pair<int, int>> &rec, int i, int sq) {
	if (i == 4) {
		for (auto x : side) if (x != sq) return 0;
		return 1;
	}
	for (int j = 0; j < 4; ++j) {
		if (side[j] + rec[i].x <= sq) {
			side[j] += rec[i].x;
			if (is_posible(rec, i + 1, sq)) return 1;
			side[j] -= rec[i].x;
		}
		if (side[j] + rec[i].y <= sq) {
			side[j] += rec[i].y;
			if (is_posible(rec, i + 1, sq)) return 1;
			side[j] -= rec[i].y;
		}
	}
	return 0;
}
void solve() {
	vector<pair<int, int>> a(4);
	int area = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> a[i].x >> a[i].y;
		area += a[i].x * a[i].y;
	}

	int L = sqrtl(area);
	if (area != L * L) {
		cout << "No\n";
		return;
	}

	for (int bt = 0; bt <= 15; ++bt) {
		vector<pair<int, int>> rec;
		for (int i = 0; i < 4; ++i) {
			pair<int, int> tmp = {a[i].y, a[i].x};
			rec.push_back((1 << i) & bt ? a[i] : tmp);
		}
		//for(auto& i : res) cout << i
		sort(rec.begin(), rec.end());
		do {
			dbg(rec)
			for (int i = 0; i < 4; ++i) side[i] = 0;
			if (is_posible(rec, 0, L)) {
				cout << "Yes\n";
				return;
			}
		} while (next_permutation(rec.begin(), rec.end()));
	}

	cout << "No\n";

}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//int tc; cin >> tc; while (tc--)
	solve();
}