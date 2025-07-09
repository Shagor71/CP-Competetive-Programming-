#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mk make_pair
const int N = 1e5 + 7, MX = N, M = 1e9 + 7;
int e;

struct Hashing {
    int chash[N][2], pw[N][2], M1 = 127657753, M2 = 987654319; 
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
    pair<int, int> get_hash(int l, int r) {
        int x[2];
        x[0] = chash[l-1][0] * pw[r-l+1][0] % M1;
        x[1] = chash[l-1][1] * pw[r-l+1][1] % M2;
        x[0] = (M1 + (chash[r][0] - x[0]) % M1) % M1;
        x[1] = (M2 + (chash[r][1] - x[1]) % M2) % M2;
        //cout << l << ' ' << r << ' ' << x[0] << ' ' << x[1] << '\n';
        return {x[0], x[1]};
    }
} H;
void solve() {
    int q;
    cin >> q;

    H.prec();

    map<pair<pair<int, int>, int>, int> cnt;
    map<int, set<pair<int, pair<int, int>>>> se;

    vector<string> a(q+5);
    vector<bool> vis(q+5, 0);
    for(int j = 1; j <= q; ++j) {
        int t;
        cin >> t;
        if(t == 1) {
            string s;
            cin >> s;
            H.hashing(s);
            for(int i = 1; i <= s.size(); ++i) {
                pair<int, int> val = H.get_hash(s.size()-i+1, s.size());
                cnt[mk(val, i)]++;
                int cn = cnt[mk(val, i)];
                if(cn-1)
                    se[i].erase(se[i].lower_bound(mk(cn-1, val)));
                se[i].insert(mk(cn, val));
                a[j] = s;
            }
            vis[j] = 1;
        }
        else if(t == 2) {
            int k, l;
            cin >> k >> l;
            int K = se[l].rbegin()->first;
            cout << (K >= k? "YES" : "NO") << '\n';
        }
        else {
            int op;
            cin >> op;
            if(!vis[op]) continue;
            H.hashing(a[op]);
            for(int i = 1; i <= a[op].size(); ++i) {
                pair<int, int> val = H.get_hash(a[op].size()-i+1, a[op].size());
                int cn = cnt[mk(val, i)];
                cnt[mk(val, i)]--;
                se[i].erase(se[i].lower_bound(mk(cn, val)));
                if(cn-1) 
                    se[i].insert(mk(cn-1, val));
            }
            vis[op] = 0;
        }
    }

}
/*
 x 4
 x 5
 se[l] = {(1, x), (3, y), (3, z), (2, x)};

*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}