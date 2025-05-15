#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> se;
    vector<int> a(n), cnt(n+1, 0);
    for(auto& i : a) cin >> i, se.insert(i), cnt[i]++;

    for(int i = n-1; i >= 0; --i) {
        if(se.size() < m) {
            cout << n - i - 1 << '\n';
            return;
        }
        cnt[a[i]]--;
        if(!cnt[a[i]]) se.erase(se.find(a[i]));
    }

    cout << n << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}