#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;


int mex(set<int> &se) {
	int i = 0, ok = 0;
	while (!se.empty()) {
		//cout << i << ' ' << *se.begin() << '\n';
		if (i != *se.begin()) ok++;
		else se.erase(se.begin());
		if (ok == 2) return i;
		i++;
	}
	return i + (ok == 0);
}
int f(int n) {
	return (n * (n + 1)) >> 1;
}
void solve() {
	int n, m;
	cin >> n >> m;

	int mx = 0;
	while (n--) {
		int l;
		cin >> l;
		set<int> se;
		while (l--) {
			int x; cin >> x;
			se.insert(x);
		}
		mx = max(mx, mex(se));
	}

	cout << (mx < m ? mx * (mx + 1) + f(m) - f(mx) : mx * (m + 1)) << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}