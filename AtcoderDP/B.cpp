#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1), dp(n + 1, 0ll);
    for (int i = 1; i <= n; ++i)  cin >> a[i];

    dp[1] = 0ll;
    for (int i = 2; i <= n; ++i) {
        dp[i] = INT_MAX;
        for (int j = 1; j <= k; ++j)
            if (i > j) dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
    }
    cout << dp[n] << '\n';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}