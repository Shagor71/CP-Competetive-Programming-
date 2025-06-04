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
    int n, k;
    cin >> n >> k;

    o_set<ll> se;
    se.insert(0);
    ll res = 0, sum = 0;
    for(int i = 1; i <= n; ++i) {
        ll x; cin >> x;
        sum += x - k;
        res += 1ll*se.order_of_key(sum+1);
        se.insert(sum);
    }

    cout << res << '\n';

}
/*
    csum[l to r] >= k * (r - l + 1)
    a + b + c + d >= 4k
    a + b + c + d - 4k >= 0
    (a - k) + (b - k) + (c - k) + (d - k) >= 0 



*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}