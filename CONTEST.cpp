#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while (T--) {

        int n; cin >> n;
        string st; cin >> st;

        vector<pair<char, char>> A(n + 1);
        for (int i = 0; i < n; i++) {
            A[i + 1] = {st[i], st[i]};
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i].first == '0') {
                int pos = i;
                while (pos <= n and A[pos].first == '0') {
                    A[pos].second = '1';
                    ans += i;
                    pos += i;
                }
            }
        }
        cout << ans << '\n';

    }
    return 0;
}