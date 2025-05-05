#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int res = 0;

	while (true) {
		sort(a.rbegin(), a.rend());
		if (!a[1]) break;
		a[0]--;
		a[1]--;
		res++;
	}
	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}