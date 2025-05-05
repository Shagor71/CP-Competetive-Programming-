#include <bits/stdc++.h>
using namespace std;


#define ll long long
int e;

void solve() {

	ll n;
	int k;
	cin >> n >> k;

	cout << "Case " << ++e << ": ";
	if (k == 2)
		cout << (n % 2 == 0 ? "Evenius" : "Oddius") << '\n';
	else
		cout << (n % 2 == 0 ? "Oddius" : "Evenius") << '\n';

}
/*


*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--) {
		solve();
	}
}