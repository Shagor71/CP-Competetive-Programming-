#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 37;

void solve() {
	int n;
	cin >> n;

	map<int, int> m;
	int q = n;
	while (q--) {
		int x;
		cin >> x;
		m[x]++;
	}
	cout << m.size() << '\n';

}
// 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 2, 3, 2
// 4, 4, 3, 2, 1
//
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}