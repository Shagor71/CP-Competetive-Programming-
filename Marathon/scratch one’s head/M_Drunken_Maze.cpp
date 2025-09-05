#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};
int n, m;
bool ok(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < m;
}
void solve() {
    cin >> n >> m;

    pair<int, int> S;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<int>> d(n, vector<int> (m, M));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if(g[i][j] == 'S') S = {i, j};
        }
    }
    
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, S});
    d[S.first][S.second] = 0;
    while(!q.empty()) {
        pair<int, int> now = q.top().second;
        if(g[now.first][now.second] == 'T') {
            int res = 0, dir = 1;
            pair<int, int> a = now, b = now, c = now;
            while(b != S) {
                //cout << b.first << ' ' << b.second << '\n';
                int mn = M-1;
                for(int i = 0; i < 4; ++i) {
                    int j = b.first + x[i], k = b.second + y[i];
                    if(ok(j, k) and mn > d[j][k]) mn = d[j][k], c = {j, k}; 
                }
                pair<int, int> l = {b.first - a.first, b.second - a.second};
                pair<int, int> r = {c.first - b.first, c.second - b.second};
                l == r ? dir++ : dir = 1;
                res++;
                if(dir == 4) dir = 2, res += 2;
                //cout << dir << ' ' << res << ", ";
                a = b, b = c;
            }
            cout << res << '\n';
            return;
        }
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int j = now.first + x[i], k = now.second + y[i];
            if(ok(j, k) and g[j][k] != '#' and d[j][k] > d[now.first][now.second] + 1) {
                d[j][k] = d[now.first][now.second] + 1;
                q.push({-d[j][k], {j, k}});
            }
        }
    }
    cout << "-1\n";
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}