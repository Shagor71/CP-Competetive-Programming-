#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 7, MX = 2e5 + 7;

int combine(int x, int y) {
	return __gcd(x, y);
}
struct Sparse_Table {
	int st[35][N], lg[N];
	int n;

	void LG() {
		lg[0] = lg[1] = 0;
		for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
		return;
	}
	void clear(int n) {
		for (int i = 0; i < 30 ; ++i)
			for (int j = 0; j < n; ++j) st[i][j] = 0;
		this->n = n;
	}
	void build(vector<int> &a) {
		n = a.size();
		for (int i = 0; i < n; ++i) st[0][i] = a[i];
		for (int i = 1; (1 << i) <= n; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = combine(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		return;
	}
	int query(int l, int r) {// index -> 0
		int i = lg[r - l + 1];
		return combine(st[i][l], st[i][r - (1 << i) + 1]);
	}
} SPT;

void solve() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n), df(n);

	for (auto &i : a) cin >> i;

	df[0] = 0;
	for (int i = 1; i < n; ++i) df[i] = abs(a[i - 1] - a[i]);

	SPT.build(df);
	//dbg(df);
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << (l == r ? 0 : SPT.query(l + 1, r)) << ' ';
	}
	cout << '\n';
	SPT.clear(n);

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	SPT.LG();
	int tc; cin >> tc; while (tc--)
		solve();
}