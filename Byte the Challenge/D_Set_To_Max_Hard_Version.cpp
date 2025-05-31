#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

struct node {
	int mx, mn;
	node() {
		mx = 0;
        mn = INT_MAX;
	}
};
node ini;
struct Sparse_Table {
	node st[2][35][N];
	int lg[N];
	int n;

	node combine(node a, node b, int flag) {
		node tmp;
		flag? tmp.mx = max(a.mx, b.mx) : tmp.mn = min(a.mn, b.mn);
		return tmp;
	}
	void LG() {
		lg[0] = lg[1] = 0;
		for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
		return;
	}
	void build(vector<int> &a, int flag) {
		n = a.size();
		for (int i = 0; i < n; ++i) flag? st[flag][0][i].mx = a[i] : st[flag][0][i].mn = a[i];
		for (int i = 1; (1 << i) <= n; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[flag][i][j] = combine(st[flag][i - 1][j], st[flag][i - 1][j + (1 << (i - 1))], flag);
		return;
	}
	node query(int l, int r, int flag) {// index -> 1
		l--, r--;
		int i = lg[r - l + 1];
		return combine(st[flag][i][l], st[flag][i][r - (1 << i) + 1], flag);
	}
} spt;
void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    vector<pair<int, int>> pos;
    for(auto& i : a) cin >> i;
    int j = 0;
    for(auto& i : b) {
        cin >> i;
        pos.push_back({i, j++});
    }
    sort(pos.begin(), pos.end());

    spt.build(a, 1);
    spt.build(b, 0);

    for(auto [x, i] : pos) {
        //int l = i;
        //int mn = x, mx = a[i];
        //cout << i+1 << ' ' << x << ":\n";
        int lo = 1, hi = i+1, ok = 0;
        while(lo <= hi) {
            int m = lo + hi >> 1;
            int mn = spt.query(m, i+1, 0).mn;
            int mx = spt.query(m, i+1, 1).mx;
            //cout << m << ' ' << i + 1 << ' ' << mn << ' ' << mx << '\n';
            if(mx == x) {
                if(mn >= x) {
                    ok = 1;
                    break;
                }
                lo = m + 1;
                continue;
            }
            mx > x ? lo = m + 1 : hi = m - 1;
        }
        if(ok) continue;
        lo = i+1, hi = n;
        while(lo <= hi) {
            int m = lo + hi >> 1;
            int mn = spt.query(i+1, m, 0).mn;
            int mx = spt.query(i+1, m, 1).mx;
            //cout << i+1 << ' ' << m << ' ' << mn << ' ' << mx << '\n';
            if(mx == x) {
                if(mn >= x) {
                    ok = 1;
                    break;
                }
                hi = m - 1;
                continue;
            }
            mx > x ? hi = m - 1 : lo = m + 1;
        }
        if(ok) continue;
        cout << "NO\n";
        return;
        // while(l >= 0 and mx < b[i] and mn >= b[i]) {
        //     mx = max(a[l], mx);
        //     mn = min(b[l], mn);
        //     l--;
        // } 
        // if(mx == b[i] and mn >= b[i]) continue;
        // int r = i;
        // mn = x, mx = a[i];
        // while(r < n and b[i] > mx and b[i] <= mn) {
        //     mx = max(mx, a[r]);
        //     mn = min(mn, b[r]);
        //     r++;
        // }
        // if(mx == b[i] and mn >= b[i]) continue;
        // cout << "NO\n";
        // return;
    }
    cout << "YES\n";
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    spt.LG();
    int tc; cin >> tc; while (tc--)
        solve();
}