#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int exp(int a, int p) {
    if(!p) return 1;
    int res = exp(a, p>>1);
    res = 1ll * res * res % M;
    if(p&1) res = 1ll * res * a % M;
    return res;
}
void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for(auto& i : a) cin >> i;
    
    vector<int> one(n, 0);
    int res = 0;
    for(int i = 19; i >= 0; --i) {
        int visit = 0, non_visit = 0;
        for(int j = 0; j < n; ++j) 
            if((1<<i)&a[j]) {
                //cout << a[j] << ' ';
                one[j]? visit++ : non_visit++;
                one[j] = 1;
            }
        if(!visit and !non_visit) continue;
        cout << i << ' ' << non_visit << ' ' << visit << '\n';
        int tmp1 = exp(2, non_visit)-1, tmp2 = exp(2, visit);
        tmp1 += 1ll*M, tmp1 %= M;
        int tmp = 1ll * tmp1 * tmp2 % M;
        res += 1ll*tmp, res %= M;
    }
    int all_ways = exp(2, n) - 1;
    all_ways += 1ll*M, all_ways %= M;
    res = (all_ways - res) % M, res += 1ll*M, res %= M;

    cout << res << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}