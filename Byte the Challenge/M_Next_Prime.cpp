#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 1e6 + 7, MX = N, M = 1e9 + 7;
int e;

vector<int> prime;
bool vis[N];
void sieve() {
    for(int i = 2; i*i < N; ++i) {
        if(vis[i]) continue;
        for(int j = i*i; j < N; j += i) vis[j] = 1;
    }
    for(int i = 2; i < N; ++i) if(!vis[i]) prime.push_back(i);
    return;
}
bool is_prime(ll x) {
    for(auto i : prime) {
        if(i*i > x) return 1;
        if(x%i == 0) return 0; 
    }
    return 1;
}
void solve() {
    ll n;
    cin >> n;

    for(ll i = n+1; ; i++) {
        if(is_prime(i)) {
            cout << i << '\n';
            return;
        }
    }

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