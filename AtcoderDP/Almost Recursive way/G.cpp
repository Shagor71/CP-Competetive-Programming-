#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e5 + 5, INF = 1e9 + 7;

int dp[N];
vector<int> g[N];

int magic(int u) {
    int &res = dp[u];
    if (res) return res;
    res = dp[u];
    for (auto v : g[u])
        res = max(res, magic(v) + 1);
    return res;
}
void solve() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (!dp[i]) res = max(res, magic(i));

    cout << res << '\n';
    //for (int i = 1; i <= n; ++i) cout << dp[i] << ' ';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}