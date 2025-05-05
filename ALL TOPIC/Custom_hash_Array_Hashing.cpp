//https://atcoder.jp/contests/abc367/tasks/abc367_f
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
} H;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1, 0), b(n + 1, 0);

    for (auto x : {0, 1}) {
        for (int i = 1; i <= n; ++i) {
            if (!x) {
                cin >> a[i];
                a[i] = a[i - 1] + H(a[i]);
            }
            else {
                cin >> b[i];
                b[i] = b[i - 1] + H(b[i]);
            }
        }
    }

    while (q--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        cout << (a[r] - a[l - 1] == b[R] - b[L - 1] ? "Yes" : "No") << '\n';
    }
}
/*


*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}