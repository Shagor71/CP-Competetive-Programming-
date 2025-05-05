#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int dp[N][4], T[N][4];
void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (auto j : {1, 2, 3}) cin >> T[i][j];
        for (auto j : {1, 2, 3})
            for (auto k : {1, 2, 3})
                if (j != k)
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + T[i][j]);
    }

    cout << max({dp[n][1], dp[n][2], dp[n][3]}) << '\n';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}