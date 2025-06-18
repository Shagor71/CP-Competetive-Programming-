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

int DQ(string s, int k, vector<vector<int>>&cnt, int l, int r) {
	if (r - l + 1 < k) return 0;
	for (int i = l; i <= r; ++i) {
		int frq = cnt[r][s[i] - 'a'] - (l ? cnt[l - 1][s[i] - 'a'] : 0);
		if (frq < k)
			return max(DQ(s, k, cnt, l, i - 1), DQ(s, k, cnt, i + 1, r));
	}
	return r - l + 1;
}
int longestSubstring(string s, int k) {
	int n = s.size();
	vector<vector<int>> cnt(n, vector<int>(26, 0));
	for (int i = 0; i < n; ++i) {
		cnt[i][s[i] - 'a']++;
		for (int j = 0; j < 26; ++j) cnt[i][j] += i ? cnt[i - 1][j] : 0;
	}
	return DQ(s, k, cnt, 0, n - 1);
}
void solve() {
	string s;
	int k;
	cin >> s >> k;

	cout << longestSubstring(s, k);

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}