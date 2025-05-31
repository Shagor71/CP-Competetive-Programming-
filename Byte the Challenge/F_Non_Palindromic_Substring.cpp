#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = min(r - i, p[l + (r - i)]);
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}
int odd[N][26], even[N][26];
void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> a = manacher(s);
    for(auto& i : a) i--;

    for(int i = 0; i <= n; ++i) 
        for(int c = 0; c < 26; ++c) odd[i][c] = even[i][c]= 0;

    for(int i = 1; i <= n; ++i) {
        int ok = (i&1);
        ok? odd[i][s[i-1]-'a']++ : even[i][s[i-1]-'a']++;
        for(int c = 0; c < 26; ++c) {
            if(ok) {
                odd[i][c] += odd[i-1][c];
                even[i][c] = even[i-1][c];
            }
            else {
                odd[i][c] = odd[i-1][c];
                even[i][c] += even[i-1][c];
            }
        }
        //cout << ok << ' ' << odd[i][0] << ' ' << even[i][0]<< '\n';
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        int L = l, R = r, ok = (l&1);
        ll len = r - l + 1;
        l--, r--;
        ll res = a[l + r] < len? len : 0;
        int cnt1 = 0, cnt2 = 0;
        if(ok) {
            cnt1 = odd[R][s[l]-'a'] - odd[L-1][s[l]-'a'];
            cnt2 = even[R][s[l+1]-'a'] - even[L-1][s[l+1]-'a'];
        }
        else {
            cnt1 = even[R][s[l]-'a'] - even[L-1][s[l]-'a'];
            cnt2 = odd[R][s[l+1]-'a'] - odd[L-1][s[l+1]-'a'];
        }
        //cout << cnt1 << ' ' << cnt2 << ' ';
        if(cnt1 + cnt2 == len) {
            if(s[l] == s[l+1]) res = 0;
            else len >>= 1, res = len*(len + 1);
        }
        else 
            res += len*(len - 1)/2 - 1;
        cout << res << '\n';
    }

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}