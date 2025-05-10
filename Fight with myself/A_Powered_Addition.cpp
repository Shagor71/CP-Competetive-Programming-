#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, x; cin >> n >> x;

    int mx = x, df = 0;
    for(int i = 0; i < n-1; ++i) {
        cin >> x;
        df = max(df, mx - x);
        mx = max(mx, x);
    }

    int res = 0;
    while(df) 
        df >>= 1, res++;
    
    cout << res << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}