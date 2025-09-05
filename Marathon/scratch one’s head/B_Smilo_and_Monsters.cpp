#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for(auto& i : a) cin >> i;
    sort(a.rbegin(), a.rend());

    ll lo = 0, hi = accumulate(a.begin(), a.end(), 0ll);
    ll res = hi;
    while(lo <= hi) {
        ll m = lo + hi >> 1;
        ll t = m;
        vector<ll> tmp = a;
        while(!tmp.empty() and t) {
            if(tmp.back() <= t) {
                t -= tmp.back();
                tmp.pop_back();
            }
            else {
                tmp.back() -= t;
                t = 0;
            }
        }
        ll sum = accumulate(tmp.begin(), tmp.end(), 0ll);
        sum <= m? (res = min(res, (ll)tmp.size()+m), hi = m - 1) : lo = m + 1;
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