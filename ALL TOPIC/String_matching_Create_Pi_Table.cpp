#include <bits/stdc++.h>
using namespace std;

vector<int> Pi_table(string s) {
    int n = s.size();
    vector<int> pi_table(n, 0);
    pi_table[0] = -1;
    for(int i = 0, j = 1; j < n; ++j) {
        if(s[i] == s[j]) pi_table[j] = ++i;
        else {
            i--;
            while(~i) {
                i = pi_table[i];
                if(~i and s[i] == s[j]) {
                    pi_table[j] = i+1;
                    break;
                }
            }
            i++;
        }
    }
    pi_table[0] = 0;
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