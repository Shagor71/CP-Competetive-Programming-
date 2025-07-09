#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int sq;
struct G {
    int i, l, r;
};

bool comp(G a, G b) {
    return (a.l / sq == b.l / sq ? (a.r > b.r) : (a.l / sq < b.l / sq));
}

int cnt[N];

bool add(int x) {
    cnt[x]++;
    return cnt[x] == 1;
}
bool rmv(int x) {
    cnt[x]--;
    return !cnt[x];
}
void solve() {
    
    int n, q; 
    cin >> n >> q;
    
	vector<int> a(n);
    vector<pair<int, int>> v;
	for(int i = 0; i < n; ++i) {
        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    int j = 0, prv = v.front().first;
    for(auto [x, i] : v) 
        j += prv != x, a[i] = j, prv = x;

	vector<G> qe(q);
	j = 0;
	for (auto &[i, l, r] : qe) {
		cin >> l >> r;
		i = j++;
	}
    
	sq = sqrtl(n);
	sort(qe.begin(), qe.end(), comp);
    
	vector<int> res(q);
	int tl = 0, tr = -1, rs = 0;
	for (auto [i, l, r] : qe) {
        l--, r--;
		while (tl < l) rs -= rmv(a[tl++]);
		while (l < tl) rs += add(a[--tl]);
		while (tr < r) rs += add(a[++tr]);
		while (r < tr) rs -= rmv(a[tr--]);
		res[i] = rs;
	}
    
	for (auto i : res) cout << i << '\n';
    
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}