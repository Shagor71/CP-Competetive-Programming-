#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 1e6 + 7, MX = N, M = 1e9 + 7;
int e;

int cnt[N];
int sieve(int n) {
    int res = 1;
    for(int i = 2; i <= n; ++i) { 
        int ok = 0;
        for(int j = i; j <= n; j += i) 
                if(cnt[j]) ok += cnt[j];
        if(ok > 1) res = max(res, i);
    }
    return res;
}
void solve() {
    int n; cin >> n;

    int mx = 0;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }
    cout << sieve(mx) << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}