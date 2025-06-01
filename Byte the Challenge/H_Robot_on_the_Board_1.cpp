#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int ro = 0, co = 0, l = 0, r = 0, u = 0, d = 0;
    int res[2] = {1, 1};
    for(auto& c : s) {
        ro += (c == 'D') - (c == 'U');
        co += (c == 'R') - (c == 'L');
        r = max(r, co);
        l = min(l, co); 
        d = max(d, ro);
        u = min(u, ro);
        if(r - l < m and d - u < n) 
            res[0] = 1 - u, res[1] = 1 - l;
    }  
    cout << res[0] << ' ' << res[1] << '\n';


}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}