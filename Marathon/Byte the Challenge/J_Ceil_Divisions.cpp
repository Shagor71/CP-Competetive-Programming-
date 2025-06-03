#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n; cin >> n;

    vector<int> v = {2, 4, 64};
    if(n != 2 and n != 4 and n != 64) v.push_back(n);
    sort(v.begin(), v.end());

    while(v.back() > n) v.pop_back();
    
    vector<pair<int, int>> res;
    for(int i = n, j = v.size() - 1; i > 2; i--) {
        if(i == v[j]) {
            j--;
            continue;
        }
        res.push_back({i, n});
    }
    while(v.size() > 1) {
        int tmp = v.back(), x = tmp;
        v.pop_back();
        while(tmp > 1) {
            res.push_back({x, v.back()});
            tmp = tmp / v.back() + (tmp%v.back() != 0);
        }
    }

    cout << res.size() << '\n';
    for(auto [x, y] : res) cout << x << ' ' << y << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}