#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 3e6 + 7, MX = N, M = 998244353;
int e;
int fact[N], ifact[N];
int exp(int a, int p) {
    if(!p) return 1;
    int res = exp(a, p>>1);
    res = 1ll * res * res % M;
    if(p&1) res = 1ll * res * a % M;
    return res;
}
void precalculate() {
    fact[0] = ifact[0] = 1;
    for(int i = 1; i < N; ++i) {
        fact[i] = 1ll*fact[i-1] * i % M;
        ifact[i] = exp(fact[i], M - 2);
    } 
    return;
}
int nCr(int n, int r) {
    return 1ll * fact[n] * ifact[r] % M * ifact[n - r] % M; 
}
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int res = 0;
    for(int i = 0; i <= c; ++i) {
        int ways = 1ll * nCr(a + b + i, b) * nCr(c - i + d - 1, d - 1) % M;
        res += ways, res %= M;
    }

    cout << res << '\n';

}
/*
three conditions
 AC
 AD
 BD

 A(A) + B(B) + C(i)  |  D  | C(C - i) + D(D - 1)
 --------------------        -------------------
 here B can move inside       here C or D both can move.
 the boundary. reason
 the above conditions.

*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalculate();
    //int tc; cin >> tc; while (tc--)
        solve();
}