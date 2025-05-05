#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e3 + 5, INF = 1e9 + 7, M = INF;

char g[N][N];
int dp[N][N];

int magic(int i, int j) {
    if (!i or !j or g[i][j] == '#') return 0;
    if (i == 1 and j == 1) return 1;
    int &res = dp[i][j];
    if (~res) return res;
    return res = (magic(i - 1, j) + magic(i, j - 1)) % M;
}
void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; j++) cin >> g[i][j];

    memset(dp, -1, sizeof dp);

    cout << magic(n, m) << '\n';

}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}