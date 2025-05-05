#include <bits/stdc++.h>
using namespace std;
#define   int   long long int
const int N = 1e5 + 7;

int phi[N], vis[N];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int p = i * i, ans = p * (p - 1) / 2;
		if (i > 2) ans -= 4 * (i  - 1) * (i - 2);
		cout << ans << '\n';
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	//int tc; cin >> tc; while(tc--)
	solve();
}
