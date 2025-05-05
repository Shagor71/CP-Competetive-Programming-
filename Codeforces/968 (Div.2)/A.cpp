#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	cout << (s.front() != s.back() ? "Yes" : "No") << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}