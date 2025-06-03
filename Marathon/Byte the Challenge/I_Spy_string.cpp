#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

bool match(string& a, string& b) {
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i) cnt += a[i] != b[i];
    return cnt <= 1;
}
bool ok(vector<string> &a, string& x) {
    for(auto s : a) 
        if(!match(s, x)) return 0;
    return 1;
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(auto& i : a) cin >> i;

    for(auto s : a) {
        for(int i = 0; i < s.size(); ++i) {
            string tmp = s;
            for(char c = 'a'; c <= 'z'; ++c) {
                tmp[i] = c;
                if(ok(a, tmp)) {
                    cout << tmp << '\n';
                    return;
                }
            }
        }
    }
    cout << "-1\n";

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}