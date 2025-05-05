#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 37;

void solve() {

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());

	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			int lo = j + 1, hi = n - 1, left = n, right = j;
			while (lo <= hi) {
				int m = lo + hi >> 1;
				a[i] + a[j] > a[m] ? (left = m, hi = m - 1) : a[i] + a[j] == a[m] ? lo = m + 1 : hi = m - 1;
			}
			lo = j + 1; hi = n - 1;
			while (lo <= hi) {
				int m = lo + hi >> 1;
				a[i] + a[j] > a[m] ? (right = m, lo = m + 1) : a[i] + a[j] == a[m] ? lo = m + 1 : hi = m - 1;
			}
			res += max(0, right - left + 1);
		}

	cout << res << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}