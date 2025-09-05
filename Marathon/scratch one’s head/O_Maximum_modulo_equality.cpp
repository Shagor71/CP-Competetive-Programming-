#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

struct node {
    int res;
    node() {
        res = 0;
    }
};
node ini;
int n;
struct SegmentTree {
    node t[3 * N];

    node combine(node l, node r) {
        node tmp;
        tmp.res = __gcd(l.res, r.res);
        return tmp;
    }

    void build(vector<int> &a, int id, int tl, int tr) {
        if (tl == tr) {
            t[id].res = a[tl - 1];
            return;
        }
        int tm = tl + tr >> 1;
        build(a, id << 1, tl, tm);
        build(a, id << 1 | 1, tm + 1, tr);
        t[id] = combine(t[id << 1], t[id << 1 | 1]);
    }

    void build(vector<int> &a) {
        n = a.size();
        build(a, 1, 1, n);
    }

    node query(int l, int r, int id, int tl, int tr) {
        if (tr < l || r < tl) return ini;
        if (l <= tl && tr <= r) return t[id];
        int tm = tl + tr >> 1;
        return combine(query(l, r, id << 1, tl, tm), query(l, r, id << 1 | 1, tm + 1, tr));
    }

    node query(int l, int r) {
        assert(n > 0);
        if (l > r) return ini;
        return query(l, r, 1, 1, n);
    }
} seg;
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n), df;
    for(auto& i : a) cin >> i;

    df.push_back(0);
    for(int i = 1; i < n; ++i) df.push_back(abs(a[i]-a[i-1]));

    seg.build(df);

    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l == r) {
            cout << "0 ";
            continue;
        }
        cout << seg.query(l+1, r).res << ' ';
    }
    cout << '\n';

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}