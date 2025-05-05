#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    sort(b.rbegin(), b.rend());

    for(auto i : b) cout << i << ' '; 
    for(auto i : a) cout << i << ' '; cout << '\n';
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc; while(tc--) 
    solve();

}