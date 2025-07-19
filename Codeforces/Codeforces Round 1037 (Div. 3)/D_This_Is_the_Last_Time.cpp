#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    int n, coin;
    cin >> n >> coin;

    vector<array<int, 3>> a(n);
    for(auto& i : a) 
        cin >> i[0] >> i[1] >> i[2];
    sort(a.begin(), a.end());

    for(auto i : a) 
        if(i[0] <= coin and coin <= i[1]) 
            coin = max(coin, i[2]);
    
    cout << coin << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}