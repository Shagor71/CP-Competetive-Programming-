#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mk make_pair
const int N = 1e5 + 7, MX = N, M = 1e9 + 7;
int e;
struct Hashing {
    ll chash[N][2], pw[N][2], M1 = 127657753, M2 = 987654319; 
    void prec() {
        pw[0][0] = pw[0][1] = 1;
        for(int i = 1; i < N; ++i) {
            pw[i][0] = pw[i-1][0] * 26 % M1;
            pw[i][1] = pw[i-1][1] * 26 % M2;
        }
    }
    void hashing(string s) {
        int i = 1;
        chash[0][0] = chash[1][1] = 0;
        for(auto c : s) {
            chash[i][0] = (chash[i-1][0] * 26 % M1 + (c - 'a' + 1)) % M1;
            chash[i][1] = (chash[i-1][1] * 26 % M2 + (c - 'a' + 1)) % M2;
            //cout << chash[i][1] << ' ';
            i++;
        }
       //cout << '\n';
    }
    pair<ll, ll> get_hash(int l, int r) {
        ll x[2];
        x[0] = chash[l-1][0] * pw[r-l+1][0] % M1;
        x[1] = chash[l-1][1] * pw[r-l+1][1] % M2;
        x[0] = (M1 + (chash[r][0] - x[0]) % M1) % M1;
        x[1] = (M2 + (chash[r][1] - x[1]) % M2) % M2;
        //cout << l << ' ' << r << ' ' << x[0] << ' ' << x[1] << '\n';
        return {x[0], x[1]};
    }
} H;
void solve() {
    string s;
    cin >> s;
 
    int n = s.size();
 
    int q; cin >> q;
    vector<string> a(q);
    set<int> sz;
    for(auto& i : a) {
        cin >> i;
        sz.insert(i.size());
    }
 
    H.hashing(s);
    //set<pair<ll, ll>> hash_val;
    map<pair<ll, ll>, bool> hash_val;
    for(auto l : sz) 
        for(int i = 1, j = l; j <= s.size(); ++i, j++) 
            //hash_val.insert(H.get_hash(i, j));
            hash_val[H.get_hash(i, j)] = 1;
 
    for(auto s : a) {
        if(s.size() > n) {
            cout << "NO\n";
            continue;
        }
        H.hashing(s);
        pair<ll, ll> now = H.get_hash(1, s.size());
        //if(hash_val.find(now) != hash_val.end()) {
        if(hash_val[now]) { 
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}
/*
sqr(5e5) * 1e5 * 
 
*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    H.prec();
    //int tc; cin >> tc; while (tc--)
        solve();
}
