#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;

pair<int, int> mex(set<int> &se) {
	int i = 0, ok = 0, x = -1;
	while (!se.empty()) {
		if (i != *se.begin()) {
			if (!ok) x = i;
			ok++;
		}
		else se.erase(se.begin());
		if (ok == 2) return {x, i};
		i++;
	}
	return {x, i + (ok == 0)};
}
int f(int n) {
	return (n * (n + 1)) >> 1;
}

set<int> path[N];
int cnt, MX, m;
bool vis[N], MEX[N];

void dfs(int u) {
	cnt += (u <= m);
	MX = max(MX, u);
	vis[u] = 1;
	for (auto v : path[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
	return;
}
void solve() {
	int n;
	cin >> n >> m;

	int mx = 0, q = n;

	priority_queue<int> pq;

	while (q--) {
		int l;
		cin >> l;
		set<int> se;
		while (l--) {
			int x; cin >> x;
			se.insert(x);
		}

		pair<int, int> p = mex(se);
		mx = max({mx, p.first, p.second});
		if (p.first == -1) pq.push(p.second), MEX[p.second] = 1;
		else {
			path[p.first].insert(p.second);
			path[p.second].insert(p.first);
			MEX[p.first] = MEX[p.second] = 1;
		}
	}

	int res = 0;
	for (int i = 0; i <= min(mx, m); ++i) {
		if (vis[i]) continue;
		cnt = 0, MX = 0;
		if (!MEX[i]) {
			if (!pq.empty() and pq.top() >= i) {
				//cout << pq.top() << ". ";
				res += pq.top(), pq.pop();
			}
			else {
				//cout << i << ".. ";
				res += i;
			}
		}
		else {
			dfs(i);
			//cout << cnt << ' ' << MX << '\n';
			res += cnt * MX;
		}
	}
	cout << mx << ' ' << m << ' ' << res << ' ' << (mx < m ? f(m) - f(mx) : 0) << '\n';

	for (int i = 0; i <= min(mx, m); ++i) vis[i] = MEX[i] = 0, path[i].clear();
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}