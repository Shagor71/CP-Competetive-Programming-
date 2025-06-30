#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
void solve() {
    ll p, q;
    cin >> p >> q;

    if(__gcd(abs(p), abs(q)) > 2) {
        cout << "-1\n";
        return;
    }
    ll x, y;
    ll cmn = ext_gcd(p, -q, y, x);
    x <<= 1, y <<= 1;
    x /= cmn, y /= cmn;
    cout << x << ' ' << y << '\n';// << (abs(x*q - y*p) == 2) << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}