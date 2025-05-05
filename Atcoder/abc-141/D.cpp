#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

void solve() {
	int n, m;
	cin >> n >> m;

	priority_queue<int> pq;
	while (n--) {
		int x;
		cin >> x;
		pq.push(x);
	}

	while (m--) {
		int mx = pq.top();
		pq.pop();
		pq.push(mx >> 1);
	}
	int res = 0;
	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}
	cout << res << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}