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

    vector<int> prf(n), suf(n);
    for(int i = 0; i < n; ++i) {
        prf[i] = a[i] + n - i - 1;
        suf[i] = a[i] + i;
    }
    //for(int i = 0; i < n; ++i) cout << prf[i] << ' ' << suf[i] << '\n';
    for(int i = 1, j = n-2; i < n; ++i, --j) {
        prf[i] = max(prf[i], prf[i-1]);
        suf[j] = max(suf[j], suf[j+1]);
    }

    //cout << "\n";
    int res = INT_MAX;
    for(int i = 0; i < n; ++i) {
        //cout << prf[i] << ' ' << suf[i] << '\n';
        res = min(res, max({i? prf[i-1] : 0, a[i], i==n-1? 0 : suf[i+1]}));
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