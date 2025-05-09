#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    sort(b.rbegin(), b.rend());

    int i = 0, j = 0;
    while(i < n and j < m) {
        if(a[i] >= b[j]) cout << a[i++] << ' ';
        else cout << b[j++] << ' '; 
        if(i == n and j == m) cout << '\n';
    }
    while(i < n) cout << a[i++] << " \n"[i == n];
    while(j < m) cout << b[j++] << " \n"[j == m];
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}