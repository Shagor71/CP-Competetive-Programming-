#include <bits/stdc++.h>
using namespace std;


#define int long long int
const int N = 2e5 + 7;

int e;


void solve() {

	int n;
	string a, b;
	cin >> n >> a >> b;

	int zero = count(a.begin(), a.end(), '0'), one = n - zero;
	e++;
	for (auto i : b) {
		if (zero == 0 or one == 0) {
			cout << "No\n";
			return;
		}
		i == '0' ? one-- : zero--;
	}
	//if(e == 50) cout << a << b;
	cout << "Yes\n";
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