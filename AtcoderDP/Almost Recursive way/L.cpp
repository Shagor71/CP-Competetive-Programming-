#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 3e3 + 5, INF = 1e9 + 7, M = INF;

int dp[N][N];
vector<int> a(N);
int n;

int magic(int i, int j) {
    if (i > j) return 0;
    int &res = dp[i][j];
    if (~res) return res;

    //if ((i + j) % 2 != n % 2) return res = max(magic(i + 1, j) + a[i], magic(i, j - 1) + a[j]);
    //return res = min(magic(i + 1, j) - a[i], magic(i, j - 1) - a[j]);
    return res = max(a[i] - magic(i + 1, j), a[j] - magic(i, j - 1));
}
void solve() {

    cin >> n;

    a.resize(n);
    for (auto& i : a) cin >> i;

    //memset(dp, -1, sizeof dp);
    for (int i = 0; i  < n + 5; i++) for (int j = 0; j < n + 5; ++j) dp[i][j] = -1;
    cout << magic(0, n - 1) << '\n';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}