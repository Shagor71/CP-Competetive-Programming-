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

vector<double> a(N);

double dp[N][N];
int n;

double magic(int i, int H) {
    if (!i) return H << 1 > n;
    double &res = dp[i][H];
    if (res != -1.0) return res;
    return res = magic(i - 1, H + 1) * a[i] + magic(i - 1, H) * (1.0 - a[i]);
}
void solve() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j <= n; ++j) dp[i][j] = -1.0;
    }

    cout << fixed << setprecision(10) << magic(n, 0) << '\n';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}