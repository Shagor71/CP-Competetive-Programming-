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
    
    H.prec();
    H.hashing(s);

    int n = s.size(), lo = 1, hi = n-1, L = n, R = -1;
    while(lo <= hi) {
        int m = lo + hi >> 1;
        set<pair<ll, ll>> se;
        int tmpL = -1, tmpR;
        for(int l = 1, r = m; r <= n; ++l, ++r) {
            pair<ll, ll> val = H.get_hash(l, r);
            int sz = se.size();
            se.insert(val);
            if(sz == se.size()) {
                tmpL = l, tmpR = r;
                break;
            }
        }
        ~tmpL? (L = tmpL, R = tmpR, lo = m + 1) : hi = m - 1;
        //return;
    }
    if(L > R) {
        cout << "-1\n";
        return;
    }
    for(int i = L-1; i < R; ++i) cout << s[i];

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}