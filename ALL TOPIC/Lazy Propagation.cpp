#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, a[N];

struct ST {
	int sum, lazy;
} tree[N * 4];

void build(int node, int l, int r) {
	if (l == r) {
		tree.sum[node] = a[l];
		return;
	}
	int m = l + r >> 1;
	int nd = node << 1;;

	build(nd, l, m), build(nd + 1, m + 1, r);
	tree.sum[node] = tree.sum[nd] + tree.sum[nd + 1];
	tree.lazy[node] = tree.lazy[nd] + tree.lazy[nd + 1];
}

void update(int node, int l, int r, int fl, int fr) {
	if (r < fl or fr < l) return;
	if (fl <= l and r <= fr) {
		tree.sum[node] = tree.lazy[node];
		return;
	}
	int m = l + r >> 1;
	int nd = node << 1;

	update(nd, l, m), update(nd + 1, m + 1, r);
	tree.sum[node] = tree.sum[nd] + tree.sum[nd + 1];
	tree.lazy[node] = tree.lazy[nd] + tree.lazy[nd + 1];
}
int query(int node, int l, int r, int fl, int fr) {
	if (r < fl or fr < l) return 0;
	if (fl <= l and r <= fr) return tree.sum[node];

	int m = l + r >> 1;
	int nd = node << 1;

	tree.sum[node] = query(nd, l, m, fl, fr) + query(nd + 1, m + 1, r, fl, fr);
}
void solve() {

	cin >> n;

	for (int i = 1; i <= n; ++i) cin >> a[i];

	build(1, 1, n);

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		update(1, 1, n, l, r);
		cout << query(1, 1, n, l, r) << '\n';
	}
}
/*
				   1-8
			  /          \
		   1-4            5-8
		 /    \          /   \
	  1-2     3-4     5-6     7-8
	 /   \   /   \   /   \   /   \
	1-1 2-2 3-3 4-4 5-5 6-6 7-7 8-8
	 1   2   3   2   2   1   2   3

	4
	2 6   a
	3 5   b
	1 3   c
	4 8   d

				               1-8


			  		/                        \
												 d
		       1-4                              5-8

		c /    		   \a,b     		 a /   		   \
	  	1-2     		3-4     		5-6     		7-8
	   /   \ a		  c/   \ d 		 b /   \           /   \
	1-1 	2-2 	3-3 	4-4 	5-5 	6-6 	7-7 	8-8


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//int tc; cin >> tc; while(tc--)
	solve();
}
