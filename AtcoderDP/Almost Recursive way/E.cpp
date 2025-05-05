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

vector<array<int, 2>> v(N);
int dp[109][N];

int magic(int n, int val) {
    if (!val or !n) return !val ? 0 : INF;

    int &wt = dp[n][val];
    //dbg(n, val, dp[n][val]);
    if (~wt) return wt;

    //not taking nth element
    wt = magic(n - 1, val);

    //taking nth elemnet
    if (val - v[n][1] >= 0)
        wt = min(wt, magic(n - 1, val - v[n][1]) + v[n][0]);

    return wt;
}
void solve() {
    int n, w;
    cin >> n >> w;

    memset(dp, -1, sizeof dp);
    for (int i = 1; i  <= n; ++i) cin >> v[i][0] >> v[i][1];

    int res = N;
    while (res--) {
        if (magic(n, res) <= w) {
            cout << res << '\n';
            return;
        }
    }
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}