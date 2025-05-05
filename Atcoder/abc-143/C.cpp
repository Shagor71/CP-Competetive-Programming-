#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 37;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int i = 0, res = 0;
	while (i < n) {
		res++;
		int j = i;
		while (i < n and s[i] == s[j]) i++;
	}

	cout << res << '\n';

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}