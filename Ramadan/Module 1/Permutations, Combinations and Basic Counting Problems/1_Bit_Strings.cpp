#include <bits/stdc++.h>
using namespace std;
#define     int    long long
#define     pb     push_back
#define     F      first
#define     S      second

const int N = 1e9 + 7, M = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = (ans * 2) % M;
	}

	cout << ans << '\n';
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	//int tc; cin >> tc; while (tc--)
	solve();
}
/*


 */