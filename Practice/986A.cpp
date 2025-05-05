#include <bits/stdc++.h>
using namespace std;


#define int long long int
int e;

struct st {
	int x, y;
};
map<char, st> m = {{'N', {0, 1}}, {'E', {1, 0}}, {'S', {0, -1}}, {'W', { -1, 0}}};

void solve() {

	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;

	int i = 0, j = 0, t = 1000;
	while (t--) {
		for (auto c : s) {
			i += m[c].x, j += m[c].y;
			if (i == a and j == b) {
				cout << "Yes\n";
				return;
			}
		}
	}
	cout << "No\n";

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--) {
		solve();
	}
}