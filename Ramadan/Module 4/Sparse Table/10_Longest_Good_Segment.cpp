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

struct node {
	ll sum;
	node() {
		sum = 0;
	}
};
node ini;
struct Sparse_Table {
	node st[35][N];
	int lg[N];
	int n;

	node combine(node a, node b) {
		node tmp;
		tmp.sum = (a.sum + b.sum);
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
		for (int i = 0; i < n; ++i) st[0][i].sum = a[i];
		for (int i = 1; (1 << i) <= n; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = combine(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		return;
	}
	node query(int l, int r) {// index -> 1
		l--, r--;
		node sum = ini;
		while (l <= r) {
			int i = lg[r - l + 1];
			sum.sum += st[i][l].sum;
			l += (1 << i);
		}
		return sum;
		int i = lg[r - l + 1];
		cout << i << ' ' << l << ' ' << r - (1 << i) + 1 << '\n';
		cout << st[i][l].sum << ' ' << st[i][r - (1 << i) + 1].sum << '\n';
		return combine(st[i][l], st[i][r - (1 << i) + 1]);
	}
} spt;


void solve() {

	int n, k, s;
	cin >> n >> k >> s;

	vector<int> a(n), path(n + 1, -1);
	for (auto& i : a) cin >> i;

	int sum = 0, j = 0;
	for (int i = 0; i < n; ++i) {
		while (j < n and sum + a[j] <= s) {
			sum += a[j++];
		}
		path[i] = j;
		cout << i << ' ' << j << '\n';
		sum -= a[i];
	}
	cout << '\n';

	for (int i = 0; i < n; ++i) {
		int j = i;
		if (!(~path[j])) continue;
		cout << i << ' ';
		while (~path[j] and path[j] != j) {
			int tmp = path[j];
			path[j] = -1;
			j = tmp;
			cout << j << ' ';
		}
		cout << '\n';
	}

}
/*

*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	spt.LG();
	int tc; cin >> tc; while (tc--)
		solve();
}