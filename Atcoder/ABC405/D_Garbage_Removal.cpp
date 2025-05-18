#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int h, w, n;
    cin >> h >> w >> n;

    map<int, set<int>> ro, co;
    while(n--) {
        int x, y;
        cin >> x >> y;
        ro[x].insert(y);
        co[y].insert(x);
    }

    int q; cin >> q;

    while(q--) {
        int t, xy;
        cin >> t >> xy;
        if(t == 1) {
            cout << ro[xy].size() << '\n';
            for(auto c : ro[xy]) 
                co[c].erase(co[c].find(xy));
            ro[xy].clear();
        }
        else {
            cout << co[xy].size() << '\n';
            for(auto r : co[xy]) 
               ro[r].erase(ro[r].find(xy));
            co[xy].clear();
        }
    }
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}