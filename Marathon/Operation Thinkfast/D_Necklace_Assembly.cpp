#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int cal(vector<int> &a, int box) {
    for(int i = a.front(); i; i--) {
        int cnt = 0;
        for(auto x : a) cnt += x/i;
        if(cnt >= box) return i*box;
    }
    return 0;
}
void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    vector<int> cnt(26, 0), a;
    for(auto c : s) cnt[c - 'a']++;
    for(auto i : cnt) 
        if(i) a.push_back(i);
    sort(a.rbegin(), a.rend());
    int res = 0;
    for(int box = 1; box*box <= k; ++box) 
        if(k%box == 0)
            res = max({res, cal(a, box), cal(a, k/box)});

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