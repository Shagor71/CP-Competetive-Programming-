#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int cal(int x) {
    int cnt = 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i) continue;
        while (x % i == 0) x /= i, cnt++;
    }
    return cnt + (x > 1);
}
void solve() {

    int n;
    cin >> n;

    int xr = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        xr ^= cal(x);
    }

    cout << (xr ? "Anna" : "Bruno") << '\n';

}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}