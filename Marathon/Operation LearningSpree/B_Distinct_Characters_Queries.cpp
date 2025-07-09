#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    string s;
    int q;
    cin >> s >> q;
 
    set<int> se[26];
    for (int i = 1; i <= s.size(); ++i) se[s[i - 1] - 'a'].insert(i);
 
    int tp, pos, l, r;
    char c;
    while (q--) {
        cin >> tp;
        if (tp == 1) {
            cin >> pos >> c;
            if (c == s[pos - 1]) continue;
            se[s[pos - 1] - 'a'].erase(pos);
            se[c - 'a'].insert(pos);
            s[pos - 1] = c;
            continue;
        }
 
        cin >> l >> r;
        int res = 0;
        for (c = 'a'; c <= 'z'; ++c) {
            auto posi = se[c - 'a'].lower_bound(l);
            res += (posi != se[c - 'a'].end() and * posi <= r);
        }
        cout << res << '\n';
 
    }

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}