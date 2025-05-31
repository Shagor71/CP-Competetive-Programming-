#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

void create(int x, int zero_cnt) {
    cout << x;
    while(zero_cnt--) cout << "0";
    return;
}
void solve() {
    int n; cin >> n;

    if(n == 1) {
        cout << "1\n";
        return;
    }
    int zero = (n - 3)>>1, cost_zero = 0;
    while(n > 0 and cost_zero <= zero) {
        create(1, cost_zero), create(6, cost_zero), create(9, (zero - cost_zero)*2);
        cout << '\n';
        cost_zero++;
        n--;
    }
    cost_zero = 0;
    while(n > 0 and cost_zero <= zero) {
        create(9, cost_zero), create(6, cost_zero), create(1, (zero - cost_zero)*2);
        cout << '\n';
        cost_zero++;
        n--;
    }
    if(n > 0) {
        cout << 19; create(6, zero*2);
        cout << '\n';
    }

}
/*
    169
    196
    691

    ((n - 3)/2 + 1) * 2 + 1 >= n
    2n  >= 2n

*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}