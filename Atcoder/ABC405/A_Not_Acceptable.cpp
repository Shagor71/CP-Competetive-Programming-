#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    if(h1 != h2) {
        cout << (h1 < h2? "No" : "Yes") << '\n';
        return;
    }
    cout << (m1 >= m2? "Yes" : "No") << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}