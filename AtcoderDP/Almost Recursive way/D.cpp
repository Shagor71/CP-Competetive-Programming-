#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;

vector<array<int, 2>> v(N);
int dp[109][N];

int magic(int n, int w) {
    if (!n or !w) return 0;

    int &res = dp[n][w];
    //dbg(n, w, dp[n][w]);
    if (~res) return res;

    //not taking nth element
    res = magic(n - 1, w);

    //taking nth elemnet
    if (w - v[n][0] >= 0)
        res = max(res, magic(n - 1, w - v[n][0]) + v[n][1]);

    return res;
}
void solve() {
    int n, w;
    cin >> n >> w;

    memset(dp, -1, sizeof dp);
    for (int i = 1; i  <= n; ++i) cin >> v[i][0] >> v[i][1];


    cout << magic(n, w) << '\n';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}