#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7, M = 1e9 + 7;

int exp(int a, int p, int M) {
	if (!p) return 1;
	int res = exp(a, p >> 1, M);
	res = (res * res) % M;
	if (p & 1) res = (res * a) % M;
	return res;
}
void solve() {

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int sum = accumulate(a.begin(), a.end(), 0ll);

	int res = 0;
	for (auto i : a) {
		sum -= i;
		res = (res + (i * sum) % M) % M;
	}

	cout << (res * exp(n, M - 1 , M)) << '\n';
}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}