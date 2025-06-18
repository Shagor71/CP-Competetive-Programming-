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
string minWindow(string s, string t) {
	int n = s.size(), m = t.size();
	vector<int> cnt1(128, 0), cnt2(128, 0);
	for (auto c : t) cnt1[c]++;

	int cur = n + 5, pos = -1;
	for (int i = 0, j = 0, sz = 0; j < n; ++j) {
		if (!cnt1[s[j]]) continue;
		cnt2[s[j]]++;
		if (cnt2[s[j]] <= cnt1[s[j]]) sz++;
		while (m <= sz) {
			if (j - i + 1 < cur) pos = i, cur = j - i + 1;
			if (cnt1[s[i]]) {
				cnt2[s[i]]--;
				if (cnt2[s[i]] < cnt1[s[i]]) sz--;
			}
			i++;
		}
	}
	if (~pos) return s.substr(pos, cur);
	return "";
}
void solve() {

	string s, t;
	cin >> s >> t;

	cout << minWindow(s, t);

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}