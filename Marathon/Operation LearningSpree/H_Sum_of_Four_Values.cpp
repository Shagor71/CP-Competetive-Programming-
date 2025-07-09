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
    for(auto &it : a) cin >> it;
    
    map<int, pair<int, int>> m;
    for(int i = 1; i <= n; ++i)
        for(int j = i+1; j <= n; ++j) 
            m[a[i-1]+a[j-1]] = make_pair(i, j);
 
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j+2 <= n; ++j) {
            int nd = k - (a[i-1]+a[j-1]);
            if(m[nd].first && m[nd].first > j) {
                cout << i <<' '<< j <<' '<< m[nd].first <<' '<< m[nd].second << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}