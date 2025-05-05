#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int dp[101][N];

void solve() {
    int n, W;
    cin >> n >> W;

    for (int i = 1; i < N; ++i) dp[0][i] = INT_MAX;
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int w, x;
        cin >> w >> x;
        for (int res = 0; res < N; ++res) {
            if (res < x)
                dp[i][res] = dp[i - 1][res];
            else
                dp[i][res] = min(dp[i - 1][res], dp[i - 1][res - x] + w);
            if (dp[i][res] <= W)
                ans = max(res, ans);
            //cout << dp[i][res] << " \n"[res == 12];
        }
    }
    cout << ans << '\n';


}
/*
        0 1 2 3 4 5 6 7 8 9 0 1 2
0
1 2 3 : 0 I I 2 I I I I I I I I I
2 1 4 : 0 I I 2 1 I I 3 I I I I I
3 2 5 : 0 I I 2 1 2 I 3 4 3 I I 5
ans = 9 [I = INF]

    dp[cur] = dp[cur-x] + w;

*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}