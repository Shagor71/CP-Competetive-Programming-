#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 3e5 + 7, MX = N, M = 1e9 + 7;
int e;

int bridge;
vector<int> g[N];
int low[N], disc[N], Time;
void dfs(int u, int par) {
    low[u] = disc[u] = ++Time;
    for (int& v : g[u]) {
        if (v == par) continue;
        if (disc[v]) {
            low[u] = min(low[u], disc[v]);
            continue;
        }
        dfs(v, u);
        if (disc[u] < low[v])
            bridge++;
        low[u] = min(low[u], low[v]);
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
    
    cout << bridge << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}