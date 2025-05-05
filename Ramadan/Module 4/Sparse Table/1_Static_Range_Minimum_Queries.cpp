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
const int N = 2e5 + 7, MX = 1e9 + 37, M = 1e9 + 7;
int e;

struct node {
	int mn;
	node() {
		mn = MX;
	}
};
node ini;
struct Sparse_Table {
	node st[35][N];
	int lg[N];
	int n;

	node combine(node a, node b) {
		node tmp;
		tmp.mn = min(a.mn, b.mn);
		return tmp;
	}
	void LG() {
		lg[0] = lg[1] = 0;
		for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
		return;
	}
	void clear(int n) {
		for (int i = 0; i < 30 ; ++i)
			for (int j = 0; j < n; ++j) st[i][j] = ini;
		this->n = n;
	}
	void build(vector<int> &a) {
		n = a.size();
		LG();
		for (int i = 0; i < n; +priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> +i) st[0][i].mn = a[i];
		for (int i = 1; (1 << i) <= n; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = combine(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		return;
	}
	node query(int l, int r) {// index -> 1
		l--, r--;
		int i = lg[r - l + 1];
		return combine(st[i][l], st[i][r - (1 << i) + 1]);
	}
} spt;

void solve() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	spt.build(a);

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << spt.query(l, r).mn << '\n';
	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}