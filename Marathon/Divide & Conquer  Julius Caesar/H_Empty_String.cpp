#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int dp[505][505];
int cal(string& s, int i, int j, int cnt) {
    cout << i << ' ' << j << '\n';
    if(cnt == s.size()) return 1;
    int &res = dp[i][j];
    if(~res) 
        return res;
    res = 0;
    if(0 <= i-1 and j+1 < s.size() and s[i-1] == s[j+1])  
        res += cal(s, i-1, j+1, cnt+2), res %= M;
    int l = i-1, r = j+1;
    while(0 <= l-1 and s[l-1] != s[l]) l--;
    while(r + 1 < s.size() and s[r] != s[r+1]) r++;
    if(0 <= l-1 and s[l-1] == s[l])
        res += cal(s, l-1, l, cnt+2), res %= M;
    if(r + 1 < s.size() and s[r] == s[r+1])
        res += cal(s, r, r+1, cnt+2), res %= M;
    return res;
}
void solve() {
    string s;
    cin >> s;

    if(s.size()&1) {
        cout << "0\n";
        return;
    }

    ll res = 0;
    for(int i = 1; i < s.size(); ++i) {
        memset(dp, -1, sizeof dp);
        if(s[i-1] == s[i]) {
            res += cal(s, i-1, i, 2), res %= M;
            cout << res << '\n';
        }
    }

    cout << res << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}