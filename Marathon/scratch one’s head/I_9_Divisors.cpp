#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 1e6 + 7, MX = N, M = 1e9 + 7;
int e;

vector<int> prime;
bool vis[N]; 
void pre() {
    for(int i = 2; i*i < N; ++i) 
        if(!vis[i])
            for(int j = i*i; j < N; j += i) vis[j] = 1;
    for(int i = 2; i < N; ++i) 
        if(!vis[i]) prime.push_back(i);
    return;
}
void solve() {
    ll n;
    cin >> n;

    int res = 0;
    for(ll i = 1; i*i <= n; ++i) {
        int cnt = 0, div = 1;
        ll tmp = i*i;
        for(auto prm : prime) {
            if(i%prm) continue;
            cnt++;
            int cn = 0;
            while(tmp % prm == 0) tmp /= prm, cn++;
            div *= (cn + 1);
            if(div == 9 and tmp == 1) res++; 
            if(cnt == 2 or prm*prm > tmp) break;
        }
    }
    cout << res << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    //int tc; cin >> tc; while (tc--)
        solve();
}