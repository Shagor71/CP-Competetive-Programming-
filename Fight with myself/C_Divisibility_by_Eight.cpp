#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
int a[3];
bool ok(int j, string& s) {
    int i = 0;
    int x = s[a[i++]]-'0';
    while(i <= j) {
        x *= 10;
        x += s[a[i++]] - '0';
    } 
    return x%8 == 0;
}
void solve() {
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); ++i) {
        a[0] = i;
        if(ok(0, s)) {
            cout << "YES\n" << s[i] << '\n';
            return;
        }
        for(int j = i + 1; j < s.size(); ++j) {
            a[1] = j;
            if(ok(1, s)) {
                cout << "YES\n" << s[i] << s[j] << '\n';
                return;
            }
            for(int k = j + 1; k < s.size(); ++k) {
                a[2] = k;
                if(ok(2, s)) {
                    cout << "YES\n" << s[i] << s[j] << s[k] << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
    

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}