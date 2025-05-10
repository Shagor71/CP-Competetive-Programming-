#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    ll a, b, g;
    cin >> a >> b >> g;

    a = a - (a%g) + (a%g == 0? 0 : g);
    b -= b%g;
    for(ll i = 0; i <= b - a; i++) {
        for(ll l = a, r = b - g*i; l <= r and r <= b; l += g, r += g) {
            if(__gcd(l, r) == g) {
                cout << l << ' ' << r << '\n';
                return;
            }
        }
    }
    cout << "-1 -1\n";

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}