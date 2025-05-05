#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 1e5 + 5, INF = 1e9 + 7, M = INF;

int dp[N];
vector<int> a(N);

bool magic(int k) {
    if (k <= 0) return k < 0 ? 1 : 0;
    int &ok = dp[k];
    if (~ok) return ok;
    ok = 1;
    for (auto i : a) ok &= magic(k - i);
    return ok = 1 - ok;
}
void solve() {
    int n, k;
    cin >> n >> k;

    a.resize(n);
    for (auto& i : a) cin >> i;

    memset(dp, -1, sizeof dp);
    cout << (magic(k) ? "First" : "Second") << '\n';
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}