#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 3e5 + 5;
const int MOD = 998244353;
int arr[MAX], dp[MAX];
void solve() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	dp[0] = 1;
	int l = 0;
	for (int i = 1; i <= n; i++) {
		while (l + 1 < i && arr[l + 1] ^ l >= x) l++;
		dp[i] = (dp[i - 1] + dp[l]) % MOD;
		cout << l << '\n';
	}
	cout << (dp[n] - 1 + MOD) % MOD << '\n';



}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}