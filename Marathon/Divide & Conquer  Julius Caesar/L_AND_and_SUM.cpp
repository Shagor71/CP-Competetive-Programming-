#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void solve() {
    ll a, s;
    cin >> a >> s;

    cout << (((s - 2*a >= 0) and !((s - 2*a)&a))? "Yes" : "No") << '\n';

}
/*
    Property:
    x + y = (x^y) + 2(x&y)
    (x+y) - 2(x&y) = x^y
     s - 2a = 

*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}