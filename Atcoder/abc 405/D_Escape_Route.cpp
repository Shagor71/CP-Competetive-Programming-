#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

char g[1003][1003];
int n, m, dp[1003][1003];
int xx[] = {-1, 0, 1, 0};
int yy[] = {0, 1, 0, -1};
char c[] = {'v', '<', '^', '>'};
bool ok(int x, int y) {
    return (0 <= x and x < n and 0 <= y and y < m and g[x][y] != '#' and g[x][y] != 'E');
}
queue<pair<int, int>> q;
void bfs() {
    while(!q.empty()) {
        int nx = q.front().first, ny = q.front().second;
        for(int i = 0; i < 4; ++i) {
            int x = nx + xx[i], y = ny + yy[i];
            if(ok(x, y) and dp[x][y] > dp[nx][ny] + 1) {
                q.push({x, y});
                dp[x][y] = dp[nx][ny] + 1;
                g[x][y] = c[i];
            } 
        }
        q.pop();
    }
    //for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cout << g[i][j] << " \n"[j == m - 1];
    //cout << '\n';
}
void solve() {

    cin >> n >> m;

    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) {
            cin >> g[i][j];
            dp[i][j] = n*m + 100;
            if(g[i][j] == 'E') q.push({i, j}), dp[i][j] = 0;
        }
    
    bfs();
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cout << g[i][j];
        cout << '\n';
    }
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}