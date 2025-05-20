#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
void insert(vector<ll>&basis, ll mask) {
    for(int i = 63; i >= 0; --i) 
        if((mask & 1ll << i)) {
            if(!basis[i]) {
                basis[i] = mask;
                return;
            }
            mask ^= basis[i];
        }
    return;
}
void solve() {
    int n; cin >> n;

    vector<ll> basis(65, 0);
    for(int i = 0; i < n; ++i) {
        ll mask; cin >> mask;
        insert(basis, mask);
    }
    //cout << msb << '\n';
    int res = 0;
    for(int i = 63; i >= 0; i--) res += (basis[i] != 0);
    
    cout << (1ll << res) - n << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}  