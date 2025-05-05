#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> k;
	string s, t;
	cin >> s >> t;
	n = s.size();
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) a += (s[i] == t[i]);
	b = n - a;
	if (k <= a) cout << k + b << '\n';
	else cout << (2 * a - k + b) << '\n';
	return 0;
}