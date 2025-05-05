#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 37;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			res += (a[i] * a[j]);

	cout << res << '\n';

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}