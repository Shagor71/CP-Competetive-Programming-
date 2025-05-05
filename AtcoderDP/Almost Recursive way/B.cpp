#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int dp[N];
vector<int> a(N);
int magic(int pos, int k, int stage = 0, char c = 'N') {
    if (!pos) return 0;
    //cout << pos << ' ' << c << ' ' << stage << '\n';
    if (~dp[pos]) return dp[pos];
    int &res = dp[pos];
    res = INT_MAX;
    //int res = INT_MAX;
    for (int i = 1; i <= k; ++i)
        if (pos >= i)
            res = min(res, magic(pos - i, k, stage + 1, 'a' + i - 1) + abs(a[pos] - a[pos - i]));
    return dp[pos];
    //return dp[pos] = res;
}
void solve() {
    int n, k;
    cin >> n >> k;

    a.resize(n);
    memset(dp, -1, sizeof dp);
    for (auto& i : a) cin >> i;

    cout << magic(n - 1, k) << '\n';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}