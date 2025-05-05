#include <bits/stdc++.h>
using namespace std;
/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/
#define int long long
#define mk make_pair
const int N = 1e6 + 5, M = 1e9 + 7;


vector<int> pr;
bool vis[N];
void seive() {
	for (int i = 2; i < N; ++i) {
		if (vis[i]) continue;
		pr.push_back(i);
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
	return;
}
void solve() {

	int n; cin >> n;
	seive();
	int res = 0;
	if (n == 1) {
		cout << "0\n";
		return;
	}
	for (auto i : pr) {
		int tmp = i;
		while (n % tmp == 0) {
			res++;
			n /= tmp;
			tmp *= i;
		}
		while (n % i == 0) n /= i;
		if (n == 1) {
			cout << res << '\n';
			return;
		}
	}
	cout << res + 1 << '\n';
}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}