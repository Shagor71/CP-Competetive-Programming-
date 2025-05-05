#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 3e2 + 5, INF = 1e9 + 7, M = INF;

double dp[N][N][N];
int n;

double magic(int i, int ii, int iii) {
    if ((i < 0 or ii < 0 or iii < 0) or (!i and !ii and !iii)) return 0;
    double &res = dp[i][ii][iii];
    if (res != -1.0) return res;
    return res = (n + i * magic(i - 1, ii, iii) + ii * magic(i + 1, ii - 1, iii) + iii * magic(i, ii + 1, iii - 1)) / (i + ii + iii);
}
void solve() {
    cin >> n;

    int a[4] = {0}, q = n;
    while (q--) {
        int x; cin >> x;
        a[x]++;
    }

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= n; ++k) dp[i][j][k] = -1.0;

    cout << fixed << setprecision(10) << magic(a[1], a[2], a[3]) << '\n';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}