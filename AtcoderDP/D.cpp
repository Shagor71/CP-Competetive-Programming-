#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int dp[101][N];
struct st {
    int w, x;
};
void solve() {
    int n, W;
    cin >> n >> W;

    vector<st> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i].w >> a[i].x;

    for (int i = 1; i <= n; ++i) {
        for (int cur = 1; cur <= W; ++cur) {
            if (cur < a[i].w) dp[i][cur] = dp[i - 1][cur];
            else
                dp[i][cur] = max(dp[i - 1][cur], dp[i - 1][cur - a[i].w] + a[i].x);
        }
    }

    cout << dp[n][W] << '\n';


}
/*
  0 1 2  3  4  5  6  7  8
1 0 0 0 30 30 30 30 30 30
2 0 0 0 30
3
    dp[cur] = dp[cur-wi] + ai;

*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}