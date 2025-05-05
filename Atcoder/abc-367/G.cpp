#include <bits/stdc++.h>
using namespace std;
#define int  long long
const int N = 1e5 + 7, MX = 1e5 + 7;

int combine(int x, int y) {
    return x + y;
}
int t[3 * N];
struct SegmentTree {
    //int t[2 * MX];
    int n;

    /*void clear(int n) {
        for (int i = 1; i < 2 * n; i++) {
            t[i] = 0; // Index 1
        }
        this->n = n;
    }*/

    void build(vector<int> &a, int id, int tl, int tr) {
        if (tl == tr) {
            t[id] = a[tl - 1]; // Index 1
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

    int query(int l, int r, int id, int tl, int tr) {
        if (tr < l or r < tl) return 0ll;
        if (l <= tl and tr <= r) return t[id];
        int tm = tl + tr >> 1;
        return combine(query(l, r, id << 1, tl, tm), query(l, r, id << 1 | 1, tm + 1, tr));
    }

    int query(int l, int r) {
        assert(n > 0);
        if (l > r) return 0;
        return query(l, r, 1, 1, n); // Index 1
    }

    void update(int pos, int val, int id, int tl, int tr) { // O(logn)
        if (tl == tr) {
            t[id] = val;
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
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;

    set<int> non_one;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] != 1) non_one.insert(i + 1);
    }
    non_one.insert(n + 1);
    seg.build(a);

    int q;
    cin >> q;
    while (q--) {
        int t, l, r, i, val;
        cin >> t >> (t != 3 ? i : l) >> (t != 3 ? val : r);
        if (t == 1) a[i - 1] = val, seg.update(i, val);
        if (t == 2) {
            if (val != 1) non_one.insert(i);
            else if (b[i - 1] != 1) non_one.erase(i);
            b[i - 1] = val;
            //for (auto it : non_one) cout << it << ' ';cout << '\n';
        }
        if (t == 3) {
            int res = a[l - 1];
            l++;
            while (l <= r) {
                int last_one_pos = min(r, *non_one.lower_bound(l));
                int tmp = seg.query(l, last_one_pos - 1);
                //cout << tmp << ' ' << last_one_pos << '\n';
                res += tmp;
                res = max(res + a[last_one_pos - 1], res * b[last_one_pos - 1]);
                l = last_one_pos + 1;
            }
            cout << res << '\n';
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}