#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mk make_pair
const int N = 2e5 + 5, M = 998244353;

int parent[N], mn[N];
void make_set(int v) {
	parent[v] = mn[v] = v;
}
int find_set(int v) {
	if (v == mn[v])
		return v;
	return mn[v] = find_set(mn[v]);
}
void solve() {

	int n; cin >> n;

	for (int i = 1; i <= n; ++i) make_set(i);

	for (int v = 2; v <= n; ++v) {
		int u; cin >> u;
		parent[v] = u;
	}

	int q; cin >> q;
	while (q--) {
		int t, u, v, x;
		cin >> t;
		if (t == 1) {
			cin >> u >> v;
			u = find_set(u), v = find_set(v);
			while (u != v) {
				mn[u] = v;
				u = parent[u];
			}
		} else {
			cin >> x;
			cout << find_set(x) << '\n';
		}
	}
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}