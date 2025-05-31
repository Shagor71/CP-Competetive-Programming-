#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

// struct node {
// 	int mx, mn;
// 	node() {
// 		mx = 0;
//         mn = INT_MAX;
// 	}
// };
// node ini;
// struct Sparse_Table {
// 	node st[35][N];
// 	int lg[N];
// 	int n;

// 	node combine(node a, node b, int flag) {
// 		node tmp;
// 		flag? tmp.mx = max(a.mx, b.mx) : tmp.mn = min(a.mn, b.mn);
// 		return tmp;
// 	}
// 	void LG() {
// 		lg[0] = lg[1] = 0;
// 		for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
// 		return;
// 	}
// 	void build(vector<int> &a, int flag) {
// 		n = a.size();
// 		for (int i = 0; i < n; ++i) flag? st[0][i].mx = a[i] : st[0][i].mn = a[i];
// 		for (int i = 1; (1 << i) <= n; i++)
// 			for (int j = 0; j + (1 << i) <= n; j++)
// 				st[i][j] = combine(st[i - 1][j], st[i - 1][j + (1 << (i - 1))], flag);
// 		return;
// 	}
// 	node query(int l, int r, int flag) {// index -> 1
// 		l--, r--;
// 		int i = lg[r - l + 1];
// 		return combine(st[i][l], st[i][r - (1 << i) + 1], flag);
// 	}
// } spt;
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

    for(auto [x, i] : pos) {
        int l = i;
        int mn = x, mx = a[i];
        while(l >= 0 and mx < b[i] and mn >= b[i]) {
            mx = max(a[l], mx);
            mn = min(b[l], mn);
            l--;
        } 
        if(mx == b[i] and mn >= b[i]) continue;
        int r = i;
        mn = x, mx = a[i];
        while(r < n and b[i] > mx and b[i] <= mn) {
            mx = max(mx, a[r]);
            mn = min(mn, b[r]);
            r++;
        }
        if(mx == b[i] and mn >= b[i]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}