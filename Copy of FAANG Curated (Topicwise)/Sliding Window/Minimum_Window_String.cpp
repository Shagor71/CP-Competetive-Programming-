#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    vector<int> cnt(26, 0);
    for(int i = 0, j = 0; i < n; ++i) {
        cnt[s[i] - 'a']++;
        if(i + 1 >= m) {
            
            j++;
        }
    }
    return 0;
}
void solve() {
    string s, t;
    cin >> s >> t;

    cout << minWindow(s, t);

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}