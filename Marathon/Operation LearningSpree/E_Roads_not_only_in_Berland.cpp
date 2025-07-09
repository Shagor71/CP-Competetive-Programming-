#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 1e3 + 7, MX = N, M = 1e9 + 7;
int e;
map<pair<int, int>, bool> bridge;
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
            bridge[{u, v}] = 1;
        low[u] = min(low[u], low[v]);
    }
}
void solve() {
    int n;
    cin >> n;

    int m = n-1;
    vector<pair<int, int>> edg;
    while(m--) {
        int u, v;
        cin >> u >> v;
        edg.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pair<int, int>> cls;
    vector<int> opn;
    for(int i = 1; i <= n; ++i) {
        if(!disc[i]) {
            opn.push_back(i);
            dfs(i, -1);
        }
    }
    for(auto i : edg) 
        if(!bridge[i] and !bridge[{i.second, i.first}]) 
            cls.push_back(i);
    
    if(cls.empty()) {
        cout << "0\n";
        return;
    }
    int u = 0;
    for(auto [i, j] : cls) 
        cout << i << ' ' << j << ' ' << opn[u] << ' ' << opn[++u] << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}