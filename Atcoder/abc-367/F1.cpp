#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int grundy[N], vis[N];

void sieve() {
    for (int i = 2; i < N; ++i) {
        if (vis[i]) continue;
        grundy[i] = 1;
        for (int j = i * i; j <= i; j += i) vis[j] = 1;
    }
    return;
}
void grundy_val() {
    for (int i = 2; i < N; ++i) {
        if (grundy[i]) continue;
        for (int j = 2; j * j < N; ++j) {
            if (i % j) continue;
            grundy[i] = grundy[i / j] + 1;
            break;
        }
    }
    return;
}
void solve() {

    int n;
    cin >> n;

    int xr = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        //xr ^= cal(x);
        xr ^= grundy[x];
    }

    cout << (xr ? "Anna" : "Bruno") << '\n';

}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    grundy_val();
    solve();
}