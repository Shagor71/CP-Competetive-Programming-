#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    vector<int> a(3);
    for(auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    cout << "Case " << ++e << ": " << (a[0]*a[0] + a[1]*a[1] == a[2]*a[2]? "yes" : "no") << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}