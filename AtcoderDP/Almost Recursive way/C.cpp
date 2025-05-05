#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

vector<array<int, 4>> v(N);
int dp[N][4];

int magic(int pos, int i) {
    if (pos == -1) return 0;
    //cout << pos << ' ' << i << '\n';
    if (dp[pos][i]) return dp[pos][i];

    int &res = dp[pos][i];

    for (auto j : {0, 1, 2})
        if (i != j) res = max(res, magic(pos - 1, j) + v[pos][i]);

    return dp[pos][i];
}
void solve() {
    int n;
    cin >> n;

    v.resize(n);
    for (auto& i : v) cin >> i[0] >> i[1] >> i[2];

    //for (auto i : v) cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    //int res = 0;
    //for (auto i : {0, 1, 2}) res = max(res, magic(n - 1, i));
    //cout << res << '\n';
    cout << magic(n, 3) << '\n';
    //for (int i = 0; i < n; ++i)
    //for (auto j : {0, 1, 2}) cout << dp[i][j] << " \n"[j == 2];
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}