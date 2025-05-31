#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<int> a(n), cnt(n+1, 0);
    int j = 1;
    for(auto& i : a) {
        cin >> i, i = j++ - i;
        if(i >= 0) cnt[i]++;
    }
    vector<int> v(k);
    for(auto& i : v) cin >> i;

    int res = 0;
    for(int i = 1; i <= k; ++i) {
        int tmp = ;
        for(int i )
        res = max(res, tmp + max(0, (d - i)/2));
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