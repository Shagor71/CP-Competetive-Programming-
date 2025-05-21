#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

bool insert(vector<int>&basis, int mask) {
    for(int i = 20; i >= 0; i--) {
        if(mask >> i & 1 ^ 1) continue;
        if(!basis[i]) return basis[i] = mask;
        mask ^= basis[i];
    }
    return 0;
}
bool xor_exist(vector<int>&basis, int x) {
    for(int i = 20; i >= 0; i--) {
        if(x >> i & 1 ^ 1) continue;
        if(!basis[i]) return 0;
        x ^= basis[i];
    }
    return 1;
}
int exp(int a, int p) {
    if(!p) return 1;
    int res = exp(a, p>>1);
    res = 1ll * res * res % M;
    if(p&1) res = 1ll * res * a % M;
    return res;
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(auto& i : a) cin >> i;
    
    int i = 0;
    vector<pair<pair<int, int>, int>> q(m);
    for(auto& [x, y] : q) cin >> x.first >> x.second, y = i++;
    sort(q.begin(), q.end());

    int sz = 0;
    vector<int> res(m), basis(21, 0);
    for(int i = 0, j = 0; i < n; ++i) {
        sz += insert(basis, a[i]);
        while(j < m and q[j].first.first == i+1) {
            ll rs = 0;
            if(xor_exist(basis, q[j].first.second)) 
                rs = exp(2, i + 1 - sz);
            res[q[j].second] = rs;
            j++;
        }
    }

    for(auto i : res) cout << i << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}