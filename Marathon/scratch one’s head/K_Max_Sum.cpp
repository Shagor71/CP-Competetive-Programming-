#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> p(n);
    for(auto& [i, j] : p) cin >> i >> j, j *= -1;
    sort(p.begin(), p.end());

    for(auto [i, j] : p) cout << i << ' '; cout << '\n';
    for(auto [i, j] : p) cout << j << ' '; cout << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}