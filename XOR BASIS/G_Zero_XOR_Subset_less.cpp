#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

bool insert(vector<int>&basis, int mask) {
    for(int i = 31; i >= 0; i--) {
        if(mask >> i & 1 ^ 1) continue;
        if(!basis[i]) return basis[i] = mask;
        mask ^= basis[i]; 
    }
    return 1;
}
void solve() {
    int n; cin >> n;
    
    vector<int> basis(32, 0);
    int xr = 0;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        xr ^= x;
        insert(basis, x);
    }

    if(!xr) {
        cout << "-1\n";
        return;
    }
    int res = 0;
    for(auto i : basis) res += i != 0;

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