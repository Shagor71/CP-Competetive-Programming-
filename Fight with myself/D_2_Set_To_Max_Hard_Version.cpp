#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = 1e9 + 37, M = 1e9 + 7;
int e;
struct node {
	int mx, mn;
	node() {
		mn = MX, mx = 0;
	}
};
node ini;
struct Sparse_Table {
	node st[35][N][2];
	int lg[N];
	int n;

	node combine(node a, node b, int flag) {
		node tmp;
        if(flag) tmp.mx = max(a.mx, b.mx), tmp.mn = MX;
        else tmp.mn = min(a.mn, b.mn), tmp.mx = 0;
		return tmp;
	}
	void LG() {
		lg[0] = lg[1] = 0;
		for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
		return;
	}
	void clear(int n) {
		for (int i = 0; i < 30 ; ++i)
			for (int j = 0; j < n; ++j) st[i][j][0] = st[i][j][1] = ini;
		this->n = n;
	}
	void build(vector<int> &a, int flag) {
		n = a.size();
		for (int i = 0; i < n; ++i) {
            node tmp;
            if(flag) tmp.mx = a[i], tmp.mn = MX;
            else tmp.mx = 0, tmp.mn = a[i];
            st[0][i][flag] = tmp;
        }
		for (int i = 1; (1 << i) <= n; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j][flag] = combine(st[i - 1][j][flag], st[i - 1][j + (1 << (i - 1))][flag], flag);
		return;
	}
	node query(int l, int r, int flag) {// index -> 1
		l--, r--;
		int i = lg[r - l + 1];
		return combine(st[i][l][flag], st[i][r - (1 << i) + 1][flag], flag);
	}
} spt;

bool ok(int l, int r, int x) {
    int max_ = spt.query(l, r, 1).mx, min_ = spt.query(l, r, 0).mn;
    //cout << l << ' ' << r << ' ' << max_ << ' ' << min_ << " 1\n";
    return (max_ == x and x <= min_);
}
void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    vector<set<int>> se(n+2);
    int j = 0;
    for(auto& i : a) {
        cin >> i;
        se[i].insert(j++);
    }
    for(auto& i : b) cin >> i;

    spt.build(a, 1);
    spt.build(b, 0);

    for(int i = 0; i < n; ++i) {
        int x = b[i];
        if(se[x].empty()) {
            cout << "NO\n";
            return;
        }
        int gd = 0;
        if(*se[x].begin() <= i) {
            int l = *(--se[x].upper_bound(i)) + 1, r = i;
            gd |= ok(l, r, x);
        }
        if(i <= *se[x].rbegin()) {
            int r = *se[x].lower_bound(i)+1, l = i+1;
            gd |= ok(l, r, x);
        }
        if(!gd) {
            cout << "NO\n";
            return;
        }
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