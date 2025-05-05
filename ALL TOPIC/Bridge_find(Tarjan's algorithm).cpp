//https://codeforces.com/contest/1986/problem/F
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector<pair<int, int>> bridge;
vector<int> g[N];
int low[N], disc[N], Time;
void dfs(int u, int par) {
    low[u] = disc[u] = ++Time;
    for (int& v : g[u]) {
        if (v == par) continue;
        if (disc[v]) { //if v was already discovered means that we found an ancestor
            low[u] = min(low[u], disc[v]);// finds the ancestor with the least discovery time
            continue;
        }
        dfs(v, u);  // recursive DFS call
        if (disc[u] < low[v]) // condition to find a bridge
            bridge.push_back({u, v});
        low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
    }
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
    for (auto i : bridge) cout << i.first << ' ' << i.second << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while(tc--)
    solve();
}