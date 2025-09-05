#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<ll> csum(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        csum[i] = csum[i-1] + (s[i-1] - '0')*i;
        //cout << csum[i] << " \n"[i == n];
    }

    vector<int> res(n);
    for(int i = n; i-1; i--) {
        res[i-1] = csum[i]%10;
        csum[i-1] += csum[i] / 10; 
    }
    res[0] = csum[1];

    for(auto i : res) cout << i;

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}