#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int dp[N];

vector<int> a(N);
int magic(int pos, int stage = 0, char c = 'N') {
    //if (pos < 1) return 0;
    //dp memoization.
    if (~dp[pos]) return dp[pos];
    //cout << pos << ' ' << stage << ' ' << c << '\n';
    dp[pos] = min(magic(pos - 1, stage + 1, 'L') + abs(a[pos] - a[pos - 1]), magic(pos - 2, stage + 1, 'R') + abs(a[pos] - a[pos - 2]));
    //cout << pos << ' ' << stage << ' ' << c << '\n';
    return dp[pos];
}
void solve() {
    int n;
    cin >> n;

    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    dp[1] = 0, dp[2] = abs(a[1] - a[2]);

    cout << magic(n) << '\n';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}