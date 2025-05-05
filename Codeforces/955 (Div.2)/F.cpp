#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
vector<int> a(N);
int mn[4 * N], mx[4 * N];

void build(int node, int l, int r) {
	if (l == r) {
		mn[node] = a[l];
		mx[node] = a[l];
		return;
	}
	int m = l + r >> 1;
	int nd = node << 1;
	build(nd, l, m), build(nd | 1, m + 1, r);
	mn[node] = min(mn[nd], mn[nd | 1]);
	mx[node] = max(mx[nd], mx[nd | 1]);
}
void update(int node, int l, int r, int pos, int x) {
	if (l == r) {
		mn[node] = x;
		mx[node] = x;
		return;
	}
	int m = l + r >> 1;
	int nd = node << 1;
	if (pos <= m) update(nd, l, m, pos, x);
	else update(nd | 1, m + 1, r, pos, x);
	mn[node] = min(mn[nd], mn[nd | 1]);
	mx[node] = max(mx[nd], mx[nd | 1]);
}
int _min(int node, int l, int r, int fl, int fr) {
	if (r < fl or fr < l) return INT_MAX;
	if (fl <= l and r <= fr) return mn[node];
	int m = l + r >> 1;
	int nd = node << 1;
	return min(_min(nd, l, m, fl, fr), _min(nd | 1, m + 1, r, fl, fr));
}
int _max(int node, int l, int r, int fl, int fr) {
	if (r < fl or fr < l) return INT_MIN;
	if (fl <= l and r <= fr) return mx[node];
	int m = l + r >> 1;
	int nd = node << 1;
	return max(_max(nd, l, m, fl, fr), _max(nd | 1, m + 1, r, fl, fr));
}
int zabe(int lo, int hi, int x, bool flag) {
	int i = flag ? lo - 1 : hi + 1;
	while (lo <= hi) {
		int m = lo + hi >> 1;
		if (flag)
			a[m] < x ? (i = m, lo = m + 1) : hi = m - 1;
		else
			a[m] > x ? (i = m, hi = m - 1) : lo = m + 1;
	}
	return i;
}
// 1 2 1 3 4
void print(set<int>&neg, int n, int MN, int MX, int L, int R) {
	cout << "min: " << MN << "(" << L << " to " << n << ") max: " << MX << "(1 to " << R - 1 << ")\na[]: ";
	for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
	cout << "\nneg: ";
	for (auto i : neg) cout << i << ' ';
	cout << "\nans: " << min(L, zabe(1, L - 1, MN, 0)) << ' ' << max(R, zabe(R, n, MX, 1))  << '\n';
	cout << "\n";
}
void result(set<int> &neg, int n) {
	if (neg.empty()) {
		cout << "-1 -1\n";
		return;
	}
	int L = *neg.begin(), R = *(--neg.end());
	int MN = _min(1, 1, n, L, n);
	int MX = _max(1, 1, n, 1, R - 1);
	//print(neg, n, MN, MX, L, R);
	cout << min(L, zabe(1, L - 1, MN, 0)) << ' ' << max(R, zabe(R, n, MX, 1))  << '\n';
	return;
}

void solve() {

	int n;
	cin >> n;

	set<int> neg;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i > 1 and a[i - 1] > a[i]) neg.insert(i);
	}

	build(1, 1, n);

	result(neg, n);

	int q;
	cin >> q;
	while (q--) {
		int x, i;
		cin >> i >> x;
		update(1, 1, n, i, x);

		if (i > 1) {
			if (a[i - 1] > a[i] and a[i - 1] <= x) neg.erase(neg.find(i));
			if (a[i - 1] > x) neg.insert(i);
		}
		if (i < n) {
			if (a[i] > a[i + 1] and x <= a[i + 1]) neg.erase(neg.find(i + 1));
			if (x > a[i + 1]) neg.insert(i + 1);
		}
		a[i] = x;
		result(neg, n);
	}

}
/*
2 3 4 1
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}