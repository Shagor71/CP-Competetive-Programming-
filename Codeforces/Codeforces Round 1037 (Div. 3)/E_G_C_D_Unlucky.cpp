#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    if(a.back() != b.front()) {
        cout << "NO\n";
        return;
    }

    int ok = 0;
    for(int i = 1; i < n; ++i) {
        if(__gcd(a[i-1], b[i]) != b.front() or a[i-1] % a[i] or b[i] % b[i-1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}