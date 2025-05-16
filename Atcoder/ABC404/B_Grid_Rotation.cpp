#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

char s[105][105], t[105][105], tmp[105][105];
int n;
void rotate() {
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) tmp[i][j] = s[j][n-i-1];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) s[i][j] = tmp[i][j];//, cout << s[i][j];
        //cout << '\n';
    }
}
int cal(int rt) {
    int res = 0;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) res += s[i][j] != t[i][j];
    //cout << res << ' ' << rt << '\n';
    return res + rt;
}
void solve() {

    cin >> n;

    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) cin >> s[i][j];
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) cin >> t[i][j];
    
    int res = INT_MAX;
    for(int i = 1; i <= 4; ++i) {
        rotate();
        res = min(res, cal(4 - i));
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