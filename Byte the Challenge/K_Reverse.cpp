#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int msb(ll x) {
    for(int i = 63; ; i--) if(x>>i & 1) return i;
}
ll reverse(ll x) {
    for(int i = 0, j = msb(x); i < j; ++i, --j)
        if(!((x>>i & 1) ^ (x>>j & 1) ^ 1))
            x ^= (1ll<<i), x ^= (1ll << j);
    return x;
}
bool left(int i, ll y) {
    y >>= i;
    return ((1ll<<(msb(y)+1)) - 1) == y;
}
bool is_equal(ll x, ll y) {
    int i = msb(x);
    while(i >= 0) {
        if((x>>i & 1) ^ (y>>i & 1)) return 0;
        i--;
    }
    return 1;
}
bool subset(ll x, ll y) {
    int ymsb = msb(y), xmsb = msb(x);
    while(ymsb >= xmsb) {
        if(is_equal(x, y) and left(xmsb, y)) return 1;
        if(!(y&1)) return 0; 
        y >>= 1;
        ymsb--;
    }
    return 0;
}
void solve() {
    ll x, y;
    cin >> x >> y;

    if(x == y) {
        cout << "YES\n";
        return;
    }
    ll nx = x;
    while(!(nx&1)) nx >>= 1;
    
    vector<ll> v;
    v.push_back(nx);
    v.push_back(reverse(nx));
    int _msb = msb(x);
    if(x != nx and _msb < 63) {
        x <<= 1ll, x++;
        v.push_back(x);
        v.push_back(reverse(x));
    }

    for(auto x : v) {
        if(subset(x, y)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}