#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 7;

int a[3][N], n;

struct ttt {
	int ps, l, r;
};
bool comp(ttt& x, ttt& y) {
	return x.ps <= y.ps;
}
bool ok(vector<int>&v, int avg) {
	int lsum, msum, rsum, i, x = 1;
	i = lsum = msum = rsum = 0ll;
	vector<ttt> pos;

	while (i < n and lsum < avg) lsum += a[v[0]][i], i++;
	pos.push_back({v[0], x, i});
	x = i + 1;
	while (i < n and msum < avg) msum += a[v[1]][i], i++;
	pos.push_back({v[1], x, i});
	x = i + 1;
	while (i < n and rsum < avg) rsum += a[v[2]][i], i++;
	pos.push_back({v[2], x, i});

	if (avg <= lsum and avg <= msum and avg <= rsum) {
		sort(pos.begin(), pos.end(), comp);
		for (auto i : pos) cout << i.l << ' ' << i.r << ' ';
		cout << '\n';
		return 1;
	}
	return 0;
}
void solve() {

	cin >> n;

	int sum;
	for (auto i : {0, 1, 2}) {
		sum = 0ll;
		for (int j = 0; j < n; ++j)
			cin >> a[i][j], sum += a[i][j];
	}

	vector<int> v = {0, 1, 2};

	do {
		if (!ok(v, (sum + 2) / 3)) continue;
		return;
	}
	while (next_permutation(v.begin(), v.end()));

	cout << "-1\n";
}
/*
	l m r

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}