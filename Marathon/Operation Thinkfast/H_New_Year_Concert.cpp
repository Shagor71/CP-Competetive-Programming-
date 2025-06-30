#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

struct node {
	int gcd;
	node() {
		gcd = 0;
	}
};
node ini;
struct Sparse_Table {
	node st[35][N];
	int lg[N];
	int n;

	node combine(node a, node b) {
		node tmp;
		tmp.gcd = __gcd(a.gcd, b.gcd);
		return tmp;
	}
	void LG() {
		lg[0] = lg[1] = 0;
		for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
		return;
	}
	void clear(int n) {
		for (int i = 0; i < 30 ; ++i)
			for (int j = 0; j < n; ++j) st[i][j] = ini;
		this->n = n;
	}
	void build(vector<int> &a) {
		n = a.size();
		LG();
		for (int i = 0; i < n; ++i) st[0][i].gcd = a[i];
		for (int i = 1; (1 << i) <= n; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = combine(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		return;
	}
	node query(int l, int r) {// index -> 1
		l--, r--;
		int i = lg[r - l + 1];
		return combine(st[i][l], st[i][r - (1 << i) + 1]);
	}
} spt;
void solve() {
    int n; 
    cin >> n;

    vector<int> a(n);
    for(auto& i : a) cin >> i;

    spt.build(a);

    vector<int> res(n, 0);
    priority_queue<int> pq;
    for(int i = 0; i < n; ++i) {
        while(!pq.empty() and abs(pq.top()) <= i) pq.pop();
        if(res[i]) continue;
        int lo = i, hi = pq.empty()? n-1 : pq.top();
        while(lo <= hi) {
            int m = lo + hi >> 1;
            int gcd = spt.query(i+1, m+1).gcd;
            if(gcd == m-i+1) {
                res[m] = 1;
                pq.push(-m);
                break;
            }
            m-i+1 > gcd? hi = m - 1 : lo = m + 1;
        }
    }

    int ans = 0;
    for(auto i : res) {
        ans += i;
        cout << ans << ' ';
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