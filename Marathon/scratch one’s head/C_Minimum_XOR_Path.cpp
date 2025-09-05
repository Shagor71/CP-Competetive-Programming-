#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

std::vector<pair<int, ll>> g[11];
int n;
ll ans = (1ll<<61);
int vst[11];
ll wgt[11][11];

void cal(int u, ll res) {
    if(u == n) {
        ans = min(ans, res);
        return;
    }
    for(int v = 1; v <= n; ++v) 
        if(!vst[v] and wgt[u][v] >= 0) {
            vst[v] = 1;
            cal(v, res ^ wgt[u][v]);
            vst[v] = 0;
        }
    return;
}
void solve() {
    int m;
    cin >> n >> m;

    memset(wgt, -1, sizeof wgt);

    while(m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        wgt[u][v] = wgt[v][u] = w;
    }
    vst[1] = 1;
    cal(1, 0);

    cout << ans << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}