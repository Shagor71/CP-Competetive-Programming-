#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

vector<int> g[N];
bool vis[N];
int cnt = 0;
void dfs(int u) {
    cnt++;
    vis[u] = 1;
    for(auto v : g[u]) 
        if(!vis[v]) dfs(v);
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> in(n+1, 0);
    while(m--) {
        int u, v; 
        cin >> u >> v;
        in[u]++, in[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) 
        if(in[i] != 2) {
            cout << "No\n";
            return;
        }
    
    dfs(1);
    cout << (cnt == n? "Yes" : "No") << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}