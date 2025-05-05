#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

void solve() {
	string a;
	cin >> a;

	cout << (a == "Sunny" ? "Cloudy" : a == "Rainy" ? "Sunny" : "Rainy") << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}