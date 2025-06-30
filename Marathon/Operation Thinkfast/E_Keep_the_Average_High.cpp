#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for(auto& i : a) cin >> i;
    int x; cin >> x;

    int csum = 0, con1 = 0, res = 0;
    for(auto i : a) {
        csum += i - x;
        if(!con1 or csum >= 0) {
            csum = min(csum, i-x);
            res++, con1 = 1;
        } 
        else con1 = 0, csum = 0; 
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