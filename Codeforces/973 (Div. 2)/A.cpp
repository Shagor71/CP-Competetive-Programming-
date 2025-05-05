#include <bits/stdc++.h>
using namespace std;
#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
#define int long long int
#define mk make_pair
const int N = 2e5 + 1, M = 1e7 + 7;

int f(int p) {
	return p * (p + 1) / 2;
}
int cal(vector<bool>&bt, vector<int>&unq, string a, string b) {
	int res = 0;
	for (int i = 0; i < b.size(); ++i) {
		int j = i, cnt = 0;
		while (j < b.size()) {
			if (a[j] == b[j]) j++, cnt++;
			else {
				bool ok = 0;
				for (int k = 0; k < bt.size(); ++k) {
					if (bt[k] and b[j] == unq[k]) {
						cnt++, j++, ok = 1;
						break;
					}
				}
				if (!ok) break;
			}
		}
		res += f(cnt);
		i = j;
	}
	dbg(res)
	return res;
}
void solve() {

	int n, k;
	string a, b;
	cin >> n >> k >> a >> b;

	if (n <= k) {
		cout << f(n) << '\n';
		return;
	}
	vector<int> unq;
	for (char c = 'a'; c <= 'z'; ++c)
		for (auto i : b)
			if (c == i) {
				unq.push_back(i);
				break;
			}

	vector<bool> bt(unq.size());

	fill(bt.begin() + unq.size() - k, bt.end(), 1);

	int res  = cal(bt, unq, a, b);
	while (next_permutation(bt.begin(), bt.end())) res = max(res, cal(bt, unq, a, b));

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