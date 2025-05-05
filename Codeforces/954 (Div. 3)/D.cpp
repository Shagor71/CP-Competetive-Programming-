#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(string &s, int pos, int rs) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1' or pos - 1 == i or pos == i) continue;
		rs += (s[i] - 48);
	}
	return rs;
}
int m[104];
void solve() {

	int n;
	string s;
	cin >> n >> s;

	if (n < 3) {
		if (s[0] == '0') cout << s[1] << '\n';
		else cout << s << '\n';
		return;
	}
	if (n == 3) {
		int a[] = {s[0] - 48, s[1] - 48, s[2] - 48};
		int x = a[0] * 10 + a[1], y = a[1] * 10 + a[2];
		cout << min({x*a[2], x + a[2], a[0]*y, a[0] + y}) << '\n';
		return;
	}

	if (count(s.begin(), s.end(), '0')) {
		cout << "0\n";
		return;
	}
	memset(m, 0, sizeof m);
	for (int i = 1; i < n; ++i) {
		int a[] = {s[i - 1] - 48, s[i] - 48};
		m[a[0] * 10 + a[1]] = i;
	}

	int res = 1000;
	for (int i = 11; i <= 99; i++)
		if (m[i])
			res = min(res, f(s, m[i], i));

	cout << res << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}