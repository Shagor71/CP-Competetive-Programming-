#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

struct node {
    ll res;
    vector<int> cnt;
    node() {
        cnt.resize(101, 0);
        res = 0;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> zoo(n);
    for(auto& i : zoo) cin >> i;

    vector<vector<int>> animals(n+1);
    for(int i = 0; i < m; ++i) {
        int _n; cin >> _n;
        for(int j = 0, zoo_i; j < _n; ++j) {
            cin >> zoo_i;
            animals[zoo_i-1].push_back(i);
        }
    }
    //for(int i = 0; i < n; ++i) {
    //    for(auto anml : animals[i]) cout << anml << ' ';
    //    cout << '\n';
    //}
    //cout << '\n';
    node dp[(1<<n) + 3];
    ll res = 1e15 + 37;
    for(int mask = 1; mask < (1<<n); ++mask) {
        for(int i = 0; (1<<i) <= mask; i++) {
            if((1<<i)&mask) {
                dp[mask].res += 1ll*zoo[i];
                for(auto x : animals[i]) dp[mask].cnt[x]++;
            }
        }
        bool ok = 1;
        //bitset<8> a(mask);
        //cout << a << ' ' << dp[mask].res << ": ";
        //for(int i = 0; i < m; ++i) cout << dp[mask].cnt[i] << ' ';
        //cout << '\n';
        for(int i = 0; i < m; ++i) {
            if(dp[mask].cnt[i] < 2) {
                ok = 0;
                break;
            }
        }
        if(ok) res = min(res, dp[mask].res);
    }

    for(int i = 1; i < (1<<n); ++i) {
        for(int j = 1; j <= i; ++j) {
            bool ok = 1;
            for(int k = 0; k < m; ++k) {
                if(dp[i].cnt[k] + dp[j].cnt[k] < 2) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                res = min(res, dp[i].res + dp[j].res);
                //bitset<8> a(i), b(j);
                //cout << a<< ' ' << b << ' ' << res << '\n';
            }
        }
    }
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