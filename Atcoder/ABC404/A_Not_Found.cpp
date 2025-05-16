#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

    string s;
    cin >> s;


    for(char c = 'a'; c <= 'z'; ++c) {
        if(!count(s.begin(), s.end(), c)) {
            cout << c << '\n';
            return;
        }
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