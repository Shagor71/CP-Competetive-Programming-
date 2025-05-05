#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());

	for (auto i : a) {
		bitset<8> x(i);
		cout << x << '\n';
	}

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}