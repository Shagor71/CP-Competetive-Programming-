#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
vector<int> t[N], euler, a(N);

struct node {
    multiset<int> se;
} ver[N];

void collect(int v, int par) {
    for(auto i : t[v]) {
        if(i == par) continue;
        for(int x : ver[i].se) {
            ver[v].se.insert(x);
            if(ver[v].se.size() > 20) ver[v].se.erase(ver[v].se.begin());
        }
    }
    return;
}
void dfs(int u, int par = -1) {
    for(auto v : t[u]) 
        if(v != par) {
            dfs(v, u);
        }
    collect(u, par);
}
int cal(int v, int kth) {
    kth = ver[v].se.size() - kth + 1; 
    for(auto i : ver[v].se) {
        kth--;
        if(!kth) return i;
    }
    return -1;
}
void solve() {
    int n, q;
    cin >> n >> q;

    
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        ver[i].se.insert(a[i]);
    }

    int m = n-1;
    while(m--) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    dfs(1);

    vector<int> res;
    vector<pair<int, int>> qu[n+5];
    for(int i = 0; i < q; ++i) {
        int v, kth;
        cin >> v >> kth;
        res.push_back(cal(v, kth));
    }
    
    for(auto i : res) cout << i << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}