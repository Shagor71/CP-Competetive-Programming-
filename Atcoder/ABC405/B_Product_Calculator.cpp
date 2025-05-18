#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    ll n;
    int k;
    cin >> n >> k;

    ll x = 1;
    while(k--) x *= 10;
    x--;
    ll res = 1;
    for(int i = 0; i < n; ++i) {
        ll j; cin >> j;
        res = res > x/j ? 1 : res * j;
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