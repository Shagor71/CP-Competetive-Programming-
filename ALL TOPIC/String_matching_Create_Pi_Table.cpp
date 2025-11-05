#include <bits/stdc++.h>
using namespace std;

vector<int> Pi_table(string s) {
    int n = s.size();
    vector<int> pi_table(n, 0);
    for(int i = 1, j = 0; i < n; ++i) {
        if(s[i] == s[j]) {
            pi_table[i] = ++j;
            continue;
        }
        j--;
        while(~j) {
            j = pi_table[j];
            if(s[j] == s[i]) {
                pi_table[i] = j + 1;
                break;
            }
            j--;
        }
        j++;
    }
    return pi_table;
}
void solve() {
    string s;
    cin >> s;

    vector<int> pi_table = Pi_table(s);
    
    for(auto i : pi_table) cout << i << ' ';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}