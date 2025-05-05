#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int p[N];

int ask(int u, int v) {
	cout << "? " << u << " " << v << '\n';
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
void dfs(int u, int v) {
	if (u == v) return;
	if (p[v]) return;
	int x = ask(u, v);
	if (x == u) {
		p[v] = u;
		return;
	}
	dfs(u, x);
	dfs(x, v);
}

void solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) p[i] = 0;

	int i = 0;
	while (++i <= n)
		if (!p[i]) dfs(1, i);

	cout << "! ";
	for (int i = 2; i <= n; i++)
		cout << i << " " << p[i] << " \n"[i == n];
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}