#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 3e3 + 7, MX = N, M = 1e9 + 7;
int e;
ll dp[N][N];
int nxt[N][N], n;

ll cal(int seg, int i) {
    if(i == n) return 1;
    ll &res = dp[seg][i];
    if(~res) return res;
    if(nxt[seg][i] == -1) return 0;
    res = cal(seg+1, nxt[seg][i]);
    if(nxt[seg][i] != n) res += cal(seg, nxt[seg][i]);
    return res%M;
}
void solve() {
    cin >> n;

    vector<ll> a(n);
    for(auto& i : a) cin >> i;

    memset(nxt, -1, sizeof nxt);
    memset(dp, -1, sizeof dp);

    for(int seg = 1; seg <= n; ++seg) {
        vector<int> last(n, -1);
        last[0] = n;
        ll sum = 0;
        for(int i = n-1; ~i; --i) {
            sum += a[i], sum %= seg;
            nxt[seg][i] = last[sum];
            last[sum] = i;
        }
    }

    cout << cal(1, 0) << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}