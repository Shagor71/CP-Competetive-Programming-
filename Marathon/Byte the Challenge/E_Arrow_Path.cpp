#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
void solve() {
    int n; cin >> n;

    vector<string> s(2);
    cin >> s[0] >> s[1];
    
    vector<vector<int>> dp(n, vector<int>(2, -1));

    queue<pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 0;
    while(!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if(i == n-1 and j and !dp[i][j]) {
            cout << "YES\n";
            return;
        }
        if(!dp[i][j]) {
            if(i + 1 < n and dp[i+1][j] != 1) {
                dp[i+1][j] = 1;
                q.push({i+1, j});
            }
            if(dp[i][1-j] != 1) {
                dp[i][1-j] = 1;
                q.push({i, 1-j});
            }
        }
        else {
            if(s[j][i] == '>' and i + 1 < n and dp[i+1][j]) {
                dp[i+1][j] = 0;
                q.push({i+1, j});
            }
            // if(s[j][i] == '<' and i and dp[i-1][j]) {
            //     dp[i-1][j] = 0;
            //     q.push({i-1, j});
            // }
        }
    }
    cout << "NO\n";
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}