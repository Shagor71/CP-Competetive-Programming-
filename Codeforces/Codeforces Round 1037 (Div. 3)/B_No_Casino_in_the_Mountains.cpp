#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(auto& i : a) cin >> i;

    int res = 0, K = k;
    for(int i = 0; i < n; ++i) {
        if(a[i]) K = k;
        else K--;
        if(!K) res++, K = k, i++;
    }

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