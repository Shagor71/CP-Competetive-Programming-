#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<int> a(n), v(k);
    int j = 1;
    for(auto& i : a) 
        cin >> i, i = j++ - i;
    for(auto& i : v) cin >> i;
    
    int res = 0;
    for(int i = 1; i <= min(d, 2*n + 1); ++i) {
        int tmp = 0;
        for(auto j : a) tmp += !j;
        res = max(res, tmp + (d-i)/2);
        int day = i%k? i%k : k;
        for(int j = 0; j < v[day-1]; ++j) a[j]--;
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