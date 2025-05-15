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
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll res = 0;
    for(auto i : a) 
        sum -= i, res += 1ll*sum * i;
    
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