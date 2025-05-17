#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 998244353;
int e;
int fact[65], ifact[65];

int exp(int a, int p) {
    if(!p) return 1;
    int res = exp(a, p>>1);
    res = 1ll * res * res % M;
    if(p&1) res = 1ll * res * a % M;
    return res;
}
void precalculate() {
    fact[0] = ifact[0] = 1;
    for(int i = 1; i < 65; ++i) {
        fact[i] = 1ll * fact[i-1] * i % M;
        ifact[i] = exp(fact[i], M-2);
    }
    return;
}
int nCr(int n, int r) {
    return 1ll * fact[n] * ifact[r] % M * ifact[n - r] % M;
}
int msb(ll n) {
    int bt = 0;
    for(int i = 0; (1ll << i) <= n; ++i) 
        if((1ll<<i)&n) bt = i;
    return bt;
}
void solve() {
    ll n;
    int k;
    cin >> n >> k;

    int res = 0, sum = 0;
    for(int i = msb(n); i >= 0 and k; --i) {
        if(((1ll<<i)&n) and i >= k) {
            int sum1 = 1ll * sum * nCr(i, k) % M;
            int sum2 = 1ll*((1ll << i) - 1) % M * nCr(i - 1, k -1) % M;
            int tmp = (sum1 + sum2) % M;
            res += tmp, res %= M;
        }
        if((1ll<<i)&n) {
            sum = (1ll*sum + (1ll<<i)%M) % M;
            k--;
        }
    }
    if(!k) 
        res += sum, res %= M;
    
    cout << res << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalculate();
    int tc; cin >> tc; while (tc--)
        solve();
}