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

    vector<pair<int, int>> a(n);
    o_set<int> se;
    for(auto& [i, j] : a) cin >> j >> i, se.insert(j);
    sort(a.rbegin(), a.rend());

    ll res = 0;
    while(!a.empty()) {
        res += 1ll*se.order_of_key(a.back().second);
        se.erase(--se.lower_bound(a.back().second));
        a.pop_back();
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