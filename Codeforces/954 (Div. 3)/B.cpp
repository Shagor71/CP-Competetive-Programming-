#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

int xx[] = { -1, 0, 0, 1};
int yy[] = {0, -1, 1, 0};

void solve() {
    int n, m;
    cin >> n >> m;

    int g[n + 5][m + 5];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> g[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int mx = -1;
            for (int k = 0; k < 4; ++k) {
                int x = i + xx[k], y = j + yy[k];
                if (0 < x and x <= n and 0 < y and y <= m)
                    mx = max(mx, g[x][y]);
            }
            if (mx != -1) g[i][j] = min(g[i][j], mx);

            cout << g[i][j] << " \n"[j == m];
        }
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}