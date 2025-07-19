#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for(auto& i : a) cin >> i;
    int pos = a[p-1];
    sort(a.begin(), a.end());

    int sec = 0;
    for(auto i : a) {
        if(i <= pos) continue;
        //cout << sec << ' ' << i << ' ' << pos + 1 << '\n';
        int vor = sec + i - pos + 1;
        if(vor > pos+1) {
            cout << "NO\n";
            return;
        }
        sec += i-pos, pos = i;
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