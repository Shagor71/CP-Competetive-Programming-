#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int q;
    cin >> q;

    multiset<int> xr, se;
    while(q--) {
        int t;
        cin >> t;
        if(t <= 2) {
            int x;
            cin >> x;
            if(t == 1) {
                if(se.empty()) {
                    se.insert(x);
                    continue;
                }
                auto it = se.lower_bound(x);
                if(it != se.end() and *it == x) {
                    se.insert(x);
                    xr.insert(0);
                    continue;
                }
                se.insert(x);
                it = se.lower_bound(x);
                auto L = it, R = it;
                int l = -1, r = -1;
                if(*L != *se.begin()) l = *(--L), xr.insert(l^x);
                if((++R) != se.end()) r = *R, xr.insert(x^r);
                if(~l and ~r) xr.erase(xr.lower_bound(l^r));
                continue;
            }
            auto it = se.lower_bound(x), L = it, R = it;
            int l = -1, r = -1;
            if(*it != *se.begin()) l = *(--L), xr.erase(xr.lower_bound(l^x));
            if((++R) != se.end()) r = *R, xr.erase(xr.lower_bound(x^r));
            if(~l and ~r) xr.insert(l^r);
            se.erase(it);
            continue;
        }
        cout << *xr.begin() << '\n';
    }
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}