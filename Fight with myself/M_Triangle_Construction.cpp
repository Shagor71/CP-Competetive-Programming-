#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for(auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    ll sum = accumulate(a.begin(), a.end(), 0ll);

    cout << min(sum/3, sum-a.back()) << '\n';
}
/*

5 2 2
*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}