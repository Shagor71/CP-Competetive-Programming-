#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int bs(vector<int> &a, int x) {
    int lo = 0, hi = a.size()-1, res = -1;
    while(lo <= hi) {
        int m = lo + hi >> 1;
        x <= a[m]? (res = a[m], hi = m - 1) : lo = m + 1; 
    }
    return res;
} 
void solve() {
    int n, mx, mn;
    cin >> n >> mx >> mn;

    vector<int> a(n);
    for(auto& i : a) cin >> i;

    ll res = 0;
    for(int i = 0; i < n; ++i) {
        vector<int> tmp, x, y;
        int j = 0;
        while(i < n and min(mn, a[i]) == mn and max(mx, a[i]) == mx) {
            if(a[i] == mn) x.push_back(j);
            if(a[i] == mx) y.push_back(j);
            tmp.push_back(a[i++]);
            j++;
        }
        for(int l = 0; l < tmp.size(); ++l) {
            int mn_r = bs(x, l), mx_r = bs(y, l);
            if(~mn_r and ~mx_r)
                res += tmp.size() - max(mn_r, mx_r);
        }
    }
    cout << res << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}