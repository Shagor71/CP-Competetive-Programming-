#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 1e6 + 7, MX = N, M = 1e9 + 7;
int e;
int fact[N], ifact[N];

int exp(int a, int p) {
    if(!p) return 1;
    int res = exp(a, p >> 1);
    res = 1ll * res * res % M;
    if(p&1) res = 1ll * res * a % M;
    return res;
}
void cal() {
    fact[0] = ifact[0] = 1;
    for(int i = 1; i < N; ++i) {
        fact[i] = 1ll * fact[i-1] * i % M;
        ifact[i] = exp(fact[i], M - 2);
    }
    return;
}
void solve() {
    int n, r;
    cin >> n >> r;

    cout << 1ll*fact[n] * ifact[r] % M * ifact[n - r] % M << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cal();
    int tc; cin >> tc; while (tc--)
        solve();
}