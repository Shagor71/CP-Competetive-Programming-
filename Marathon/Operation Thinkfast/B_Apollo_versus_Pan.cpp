#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n; cin >> n;

    vector<ll> a(n), cnt(64, 0);
    for(auto& i : a) {
        cin >> i;
        int j = 0;
        ll x = i;
        while(x) cnt[j++] += (x&1), x >>= 1ll;
    }

    ll res = 0;
    for(auto j : a) {
        ll x_and = 0, y_or = 0;
        for(int i = 0; i < 61; ++i) {
            if(j>>i&1) {
                x_and += (1ll<<i)%M * cnt[i] % M;
                y_or += (1ll<<i)%M * n % M;
                x_and %= M, y_or %= M;
                continue;
            }
            y_or += (1ll<<i)%M * cnt[i] % M;
            y_or %= M;
        }
        res += x_and * y_or % M;
        res %= M;
    }
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