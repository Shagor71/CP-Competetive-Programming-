#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, q;
    cin >> n >> q;

    set<int> one;
    for(int i = 0, x; i < n; ++i) {
        cin >> x;
        if(x == 1) one.insert(i);
    }

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int sum; cin >> sum;
            int total = one.size() + 2*(n - one.size());
            if(total < sum) {
                cout << "NO\n";
                continue;
            }
            if(one.empty()) {
                cout << (sum&1? "NO" : "YES") << '\n';
                continue;
            }
            int sf = n - *one.begin(), pf = *one.rbegin() + 1;
            int suf = one.size() + (sf - one.size())*2, prf = one.size() + (pf - one.size())*2;
            if(sum <= max(suf, prf)) {
                cout << "YES\n";
                continue;
            }
            cout << ((total%2 == sum%2) ? "YES" : "NO") << '\n';
            continue;
        }
        int i, x;
        cin >> i >> x;
        if(x == 1) 
            one.insert(i-1);
        else if(!one.empty() and one.find(i-1) != one.end()) 
            one.erase(one.find(i-1)); 
    }   

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
    solve();
}