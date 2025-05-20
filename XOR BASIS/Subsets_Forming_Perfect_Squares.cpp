#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

vector<int> prime;
void sieve() {
    vector<bool> vis(301, 0); 
    for(int i = 2; i <= 300; ++i) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i*i; j <= 300; j += i) vis[j] = 1;
    }
    return;
}
bool insert(vector<ll>&basis, ll mask) {
    for(int i = 63; i >= 0; --i) {
        if(mask >> i & 1 ^ 1) continue;
            if(!basis[i]) 
                return basis[i] = mask;
            
            mask ^= basis[i];
    }
    return 0;
}
vector<ll> v;
void solve() {
    int n; cin >> n;
 
    int cnt = n;
    vector<ll> basis(65, 0);
    for(int i = 0; i < n; ++i) {
        ll x; cin >> x;
        ll mask = 0;
        for(int j = 0; j < prime.size(); ++j) {
            int xr = 0;
            while(x % prime[j] == 0) x /= prime[j], xr ^= 1;
            mask |= (1ll << j)*xr;
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

    cout << "Case " << ++e << ": " << res << '\n';
    
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int tc; cin >> tc; while (tc--)
        solve();
}  