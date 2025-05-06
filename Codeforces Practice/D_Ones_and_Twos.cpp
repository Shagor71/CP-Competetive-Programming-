#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, m; 
    cin >> n >> m;
    
    set<int> s;
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        sum += x;
        if(x == 1) se.insert(i);
    }
    
    while(m--) {
        int t; cin >> t;
        if(t == 1) {
            int x; cin >> x;
            if(sum < x) {
                cout << "No\n";
                continue;
            }
            if(x&1) {
                if(se.empty()) {
                    cout << "No\n";
                    continue;
                }
                int lf = se.size() + 2*(*se.rbegin()-se.size());
                int rt = se.size() + 2*(n - *se.begin() + 1 - se.size());
                if(lf >= x or rt >= x or se.size()) 
                    cout <<  "Yes\n";
                else {
                    
                }
                continue;
            }
            if(se.empty()) cout << "Yes\n";
            else {
                int lf = se.size() + 2*(*se.rbegin()-se.size());
                int rt = se.size() + 2*(n - *se.begin() + 1 - se.size());
                cout << ((lf >= x or rt >= x)? "Yes" : "No") << '\n';
                continue;
            }
            continue;
        }
    }
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}