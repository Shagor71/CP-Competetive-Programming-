#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;


void solve() {

    int n, k;
    cin >> n >> k;

    map<int, vector<int>> a;
    map<int, int> m;

    while (n--) {
        int x;
        cin >> x;
        a[x % k].push_back(x);
        m[x]++;
    }

    int cnt = 0, res = 0;
    for (auto& i : a) {
        int sz = i.second.size();
        cnt += sz % 2;
        if (cnt == 2) {
            cout << "-1\n";
            return;
        }
        sort(i.second.begin(), i.second.end());
        if (sz & 1) {
            vector<int> v = i.second, csum0(sz + 1, 0), csum1(sz + 1, 0);
            for (int j = 1; j < sz; ++j) {
                if (j & 1) {
                    csum0[j] = csum0[j - 1] + v[j] - v[j - 1];
                    csum1[j] = csum1[j - 1];
                }
                else {
                    csum1[j] = csum1[j - 1] + v[j] - v[j - 1];
                    csum0[j] = csum0[j - 1];
                }
                //cout << csum0[j] << ' ' << csum1[j] << '\n';
            }

            int mn = INT_MAX;
            for (int j = 0; j < sz; ++j) {
                if (j % 2 == 0) {
                    //cout << csum0[j] << ' ' << csum1[sz - 1] - csum1[j] << ".\n";
                    mn = min(mn, csum0[j] + csum1[sz - 1] - csum1[j]);
                }
                else {
                    //cout << csum0[j - 1] << ' ' << v[j + 1] - v[j - 1]  << ' ' << (j + 1 == sz ? 0ll : csum1[sz - 1] - csum1[j + 1]) << "..\n";
                    mn = min(mn, csum0[j - 1] + v[j + 1] - v[j - 1] + csum1[sz - 1] - csum1[j + 1]);
                }
            }
            //cout << '\n'<< mn << ' ';
            res += mn;

        }
        else {
            for (int j = 1; j < sz; j += 2)
                res += i.second[j] - i.second[j - 1];
        }
    }
    cout << res / k << '\n';
}
/*

*/
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}