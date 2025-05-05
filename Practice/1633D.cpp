#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;

struct scc {
	vector<vector<ll>> edges, redges;
	vector<bool> used;
	vector<ll> order, component;
	ll m;
	void init(ll _m) {
		    = _m;
		edges = vector<vector<ll>>(m);
		redges = vector<vector<ll>>(m);
		order.clear(); component.clear();
	}
	void edge(ll u, ll v) {
		// indexing, i = 0;
		edges[u].push_back(v);
		redges[v].push_back(u);
	}
	void dfs1(ll v) {
		used[v] = true;
		for (ll i = 0; i < edges[v].size(); i++) if (!used[edges[v][i]]) dfs1(edges[v][i]);
		order.push_back(v);
	}
	void dfs2(ll v) {
		used[v] = true;
		component.push_back(v);
		for (ll i = 0; i < redges[v].size(); i++) if (!used[redges[v][i]]) dfs2(redges[v][i]);
	}
	vector<vector<ll>> run() {
		vector<vector<ll>> components;
		used.assign(m, false);
		for (ll i = 0; i < m; i++) if (!used[i]) dfs1(i);
		used.assign(m, false);
		for (ll i = 0; i < m; i++) {
			ll v = order[m - 1 - i];
			if (!used[v]) {
				dfs2(v);
				components.push_back(component);
				component.clear();
			}
		}
		return components;
	}
} S;

struct st {
	ll mx, fr;
};

vector<ll> cost(N);
map<ll, ll> comp, ind;
map<pair<ll, ll>, ll> frq;

vector<st> a;
st combine(st x, st y) {
	if (x.mx == y.mx) return {x.mx, x.fr + y.fr};
	return (x.mx > y.mx ? x : y);
}
map<pair<ll, ll>, st> t;
struct SegmentTree {
	int n;

	void build(vector<st> &a, int id, int tl, int tr, int ci) {
		if (tl == tr) {
			t[mk(id, ci)] = a[tl - 1]; // Index 1
			cout << id << ' ' << t[mk(id, ci)].mx << ' ' << t[mk(id, ci)].fr << '\n';
			return;
		}
		int tm = tl + tr >> 1;
		build(a, id << 1, tl, tm, ci), build(a, id << 1 | 1, tm + 1, tr, ci);
		t[mk(id, ci)] = combine(t[mk(id << 1, ci)], t[mk(id << 1 | 1, ci)]);
		cout << id << ' ' << t[mk(id, ci)].mx << ' ' << t[mk(id, ci)].fr << '\n';
	}

	void build(vector<st> &a, int ci) {
		n = a.size();
		build(a, 1, 1, n, ci); // Index 1
	}

	/*void update(int pos, st val, int id, int tl, int tr) { // O(logn)
		if (tl == tr) {
			t[id] = val;
			return;
		}
		int tm = tl + tr >> 1;
		pos <= tm ? update(pos, val, id << 1, tl, tm) : update(pos, val, id << 1 | 1, tm + 1, tr);
		t[id] = combine(t[id << 1], t[id << 1 | 1]);
	}

	void update(int pos, st val) {
		assert(n > 0);
		update(pos, val, 1, 1, n); // Index 1
	}*/
} seg;


void solve() {


	int n, m, q;
	cin >> n >> m >> q;

	S.init(m);

	int mm = m;
	while (mm--) {
		int u, v;
		cin >> u >> v;
		S.edge(u - 1, v - 1);
	}

	cost.resize(n);
	for (int i = 0; i < n; ++i) cin >> cost[i];

	vector<vector<ll>> CC = S.run();

	set<tuple<int, int, int>> res;

	int i = 0;
	vector<st> C[CC.size()];
	for (auto v : CC) {
		int j = 0;
		for (auto x : v) frq[mk(i, cost[x])]++;
		for (auto x : v) {
			cout << cost[x] << ' ';
			C[i].push_back({cost[x], frq[mk(i, cost[x])]});
			ind[x] = j++;
		}
		cout << ":\n";
		seg.build(C[i], i);
		cout << "end\n";
		//cout << seg.query() << '\n';
		i++;
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