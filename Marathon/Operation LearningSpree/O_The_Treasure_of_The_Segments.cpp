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
    for(auto& [l, r] : a) cin >> l >> r;
    sort(a.begin(), a.end());

    o_set<pair<int, int>> se;
    int res = 1, i = 0;
    for(auto [l, r] : a) {
        int avb = i - se.order_of_key({l, -1});
        int blw = 0, lo = i+1, hi = n-1;
        while(lo <= hi) {
            int m = lo + hi >> 1;
            a[m].first <= r? (blw = m - i, lo = m + 1) : hi = m - 1;
        }
        //cout << avb  << ' ' << blw << '\n';
        res = max(res, avb + blw + 1);
        i++;
        se.insert({r, 0});
    }

    cout << n - res << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}