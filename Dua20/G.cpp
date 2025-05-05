#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	while (cin >> n) {

		vector<int> v(n);
		for (auto &x : v) cin >> x;
		int flag = (n + 1) & 1;
		for (int i = 1; i <= (n / 2); i++) if (v[i] <= v[i - 1] || v[i - 1] != v[n - i]) {
				flag = 1;
				break;
			}
		cout << (flag ? "Not perfect" : "Perfect") << '\n';

	}
	return 0;
}