#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

vector<pair<int, int>> bridge;
vector<int> g[N];
int low[N], disc[N], times, dp[N];

void dfs(int u, int par) {
    low[u] = disc[u] = ++times;
    for (int& v : g[u]) {
        if (v == par) continue;
        if (disc[v]) {
            low[u] = min(low[u], disc[v]);
            continue;
        }
        dfs(v, u);
        dp[u] += dp[v] + 1;
        //cout << "(" << v << ' ' << u << ")";
        if (disc[u] < low[v])
            bridge.push_back({u, v});
        low[u] = min(low[u], low[v]);
    }
}
int f(int x) {
    return x * (x - 1) >> 1ll;
}
void reset(int n) {
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        low[i] = disc[i] = dp[i] = 0ll;
    }
    bridge.clear();
    times = 0;
}
void solve() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        if (!disc[i]) dfs(i, i);
    int res = f(n);
    for (auto i : bridge) {
        int a = min(dp[i.first], dp[i.second]) + 1, b = n - a;
        res = min(res, f(a) + f(b));
        //cout << i.first << ' ' << i.second << ' ' << dp[i.first] << ' ' << dp[i.second] << '\n';
    }
    cout << res << '\n';
    reset(n);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}