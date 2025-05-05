#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mk make_pair
const int N = 1e6 + 7, MX = N, M = 1e5 + 7;
int ee;

bool SS(vector<int>& arr, int n, int sum) {

	if (sum == 0)
		return true;
	if (n == 0)
		return false;

	if (arr[n - 1] > sum)
		return SS(arr, n - 1, sum);

	return SS(arr, n - 1, sum) || SS(arr, n - 1, sum - arr[n - 1]);
}

bool isSubsetSum(vector<int>& arr, int sum) {
	return SS(arr, arr.size(), sum);
}
void solve() {

	int m;
	cin >> n >> m >> d;

	a.resize(n);
	for (auto &i : a) cin >> i;

	memset(dp, -1, sizeof dp);

	cout << cal(0, m, 0) << ' ' << ans << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	////int tc; cin >> tc; while (tc--)
	solve();
}