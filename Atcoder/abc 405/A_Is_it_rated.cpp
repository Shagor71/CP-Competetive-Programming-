#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int r, x;
    cin >> r >> x;

    if(x == 1) {
        cout << ((1600 <= r and r <= 2999) ? "Yes" : "No") << '\n';
    }
    else  {
         cout << ((1200 <= r and r <= 2399) ? "Yes" : "No") << '\n';
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