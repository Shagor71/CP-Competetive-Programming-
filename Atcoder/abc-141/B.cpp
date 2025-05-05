#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

void solve() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'U' or s[i] == 'D' or (s[i] == 'R' and i % 2 == 0) or (s[i] == 'L' and i & 1)) continue;
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}