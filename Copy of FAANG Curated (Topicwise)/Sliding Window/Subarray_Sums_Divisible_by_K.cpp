#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
int subarraysDivByK(vector<int>& a, int k) {
	vector<int> f(k, 0);
	f[0] = 1;
	int sum = 0, res = 0;
	for (auto i : a) {
		sum = (sum + i) % k;
		sum += k, sum %= k;
		res += f[sum];
		f[sum]++;
	}
	return res;
}
void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	cout << subarraysDivByK(a, k);

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}