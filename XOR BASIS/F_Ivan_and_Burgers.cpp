#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 5e5 + 7, MX = N, M = 1e9 + 7;
int e;
struct node {
	vector<int> basis;
	node() {
		basis.resize(21, 0);
	}
};
node ini;
struct SegmentTree {
	node t[3 * N];
	int n;
    
    void operation(node& tmp, int mask, int i) {
        if(!mask) return;
        for(; ~i; i--) {
                if(mask >> i & 1 ^ 1) continue;
                if(!tmp.basis[i]) {
                    tmp.basis[i] = mask;
                    return;
                }
                mask ^= tmp.basis[i];
            }
        return;
    }
	node combine(node l, node r) {
        int L = 0, R = 0;
        for(int i = 20; ~i; i--) L += l.basis[i] != 0, R += r.basis[i] != 0;
        if(!L or !R) return L? l : r;
        for(int i = 20; ~i; i--) 
            if(r.basis[i]) operation(l, r.basis[i], i);
		return l;
	}

	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
            node tmp;
            operation(tmp, a[tl-1], 20);
			t[id] = tmp; // Index 1
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
} seg;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for(auto& i : a) cin >> i;

    seg.build(a);
    
    int q; cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        node tmp = seg.query(l, r);
        int res = 0;
        for(int i = 20; ~i; i--) 
            res = max(res, res^tmp.basis[i]);
        cout << res << '\n';
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