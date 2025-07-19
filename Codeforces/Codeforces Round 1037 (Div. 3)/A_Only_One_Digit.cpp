#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {

    string s;
    cin >> s;

    char res = '9';
    for(auto i : s) res = min(res, i);

    cout << res << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}