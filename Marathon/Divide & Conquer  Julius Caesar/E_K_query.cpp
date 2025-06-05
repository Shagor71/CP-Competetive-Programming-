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
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& i : a) cin >> i;

    int q; cin >> q;
    vector<pair<pair<int, int>, int>> qu(q);
    vector<vector<pair<int, int>>> L(n+1), R(n+1);
    int j = 0;
    for(auto& [i, k] : qu) {
        cin >> i.first >> i.second >> k;
        L[i.first].push_back({k, j});
        R[i.second].push_back({k, j++});
    }

    o_set<int> se;
    vector<int> res(q);
    for(int i = 1; i <= n; ++i) {
        for(auto [k, j] : L[i]) {
            int boro = se.size() - se.order_of_key(k+1);
            res[j] = boro;
        }
        se.insert(a[i-1]);
        for(auto [k, j] : R[i]) {
            int boro = se.size() - se.order_of_key(k+1);
            res[j] = boro - res[j];
        }
    }

    for(auto i : res) cout << i << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}