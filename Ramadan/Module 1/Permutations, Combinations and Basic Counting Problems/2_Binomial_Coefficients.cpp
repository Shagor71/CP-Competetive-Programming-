#include <bits/stdc++.h>
using namespace std;
#define  ll    long long
const int   N = 1e6 + 7, M = 1e9 + 7;

int fct[N], invrs[N];

int biexp(int a, int p) {
    if (!p) return 1 % M;
    int res = biexp(a, p >> 1);
    res = ((ll)res * (ll)res) % M;
    res = p & 1 ? ((ll)res * (ll)a) % M : (ll)res;
    return res;
}
void fact() {
    for (int i = 1; i < N; ++i) {
        fct[i] = ((ll)fct[i - 1] * (ll)i) % M;
        invrs[i] = biexp(fct[i], M - 2);
    }
    return;
}

void solve() {
    int x, y;
    cin >> x >> y;

    cout << ((((ll)fct[x] * (ll)invrs[y]) % M) * (ll)invrs[x - y]) % M << '\n';
}
/*
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fct[0] = invrs[0] = 1;
    fact();
    int tc; cin >> tc; while (tc--)
        solve();
}