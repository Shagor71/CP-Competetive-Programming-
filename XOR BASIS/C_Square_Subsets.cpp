#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

vector<int> prime;
void sieve() {
    vector<int> vis(75, 0);
    for(int i = 2; i <= 70; i++) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i*i; j <= 70; j += i) vis[j] = 1;
    }
    return;
}
bool insert(vector<int>& basis, int mask) {
    for(int i = 19; i >= 0; i--) {
        if(mask >> i & 1 ^ 1) continue;
        if(!basis[i]) return basis[i] = mask;
        mask ^= basis[i];
    }
    return 0;
}
void solve() {
    int n; cin >> n;

    int cnt = n;
    vector<int>  basis(20, 0);
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        int mask = 0;
        for(int j = 0; j < prime.size(); ++j) {
            int xr = 0;
            while(x % prime[j] == 0) xr ^= 1, x /= prime[j];
            mask |= (1 << j)*xr;
        }
        cnt -= insert(basis, mask);
    } 

    ll res = 1;
    while(cnt--) {
        res <<= 1ll;
        if(res >= M) res -= M;
    } 
    res--;
    if(res < 0) res += M;
    
    cout << res << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    //int tc; cin >> tc; while (tc--)
        solve();
}