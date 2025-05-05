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
        tmp.res = (l.res + r.res) % M;
        return tmp;
    }

    void build(vector<int> &a, int id, int tl, int tr) {
        if (tl == tr) {
            t[id].res = a[tl - 1]; // Index 1
            return;
        }
        int tm = tl + tr >> 1;
        build(a, id << 1, tl, tm), build(a, id << 1 | 1, tm + 1, tr);
        t[id] = combine(t[id << 1], t[id << 1 | 1]);
    }

    void build(vector<int> &a) {
        n = a.size();
        build(a, 1, 1, n); // Index 1
    }

    node query(int l, int r, int id, int tl, int tr) {
        if (tr < l or r < tl) return ini;
        if (l <= tl and tr <= r) return t[id];
        int tm = tl + tr >> 1;
        return combine(query(l, r, id << 1, tl, tm), query(l, r, id << 1 | 1, tm + 1, tr));
    }

    node query(int l, int r) {
        assert(n > 0);
        if (l > r) return ini;
        return query(l, r, 1, 1, n); // Index 1
    }

    void update(int pos, int val, int id, int tl, int tr) { // O(logn)
        if (tl == tr) {
            t[id].res = val;
            return;
        }
        int tm = tl + tr >> 1;
        pos <= tm ? update(pos, val, id << 1, tl, tm) : update(pos, val, id << 1 | 1, tm + 1, tr);
        t[id] = combine(t[id << 1], t[id << 1 | 1]);
    }

    void update(int pos, int val) {
        assert(n > 0);
        update(pos, val, 1, 1, n); // Index 1
    }
} seg;

void solve() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto& i : a) cin >> i;

    seg.build(a);

    while (q--) {
        int t; cin >> t;
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r).res << '\n';
            continue;
        }
        int i, x;
        cin >> i >> x;
        seg.update(i, x);
    }

}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
    solve();
}