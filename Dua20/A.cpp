#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	vector<int> cnt(30);
	for (auto c : s) cnt[c - 'a']++;
	for (char c = 'a'; c <= 'z'; c++) if (cnt[c - 'a']) cout << c << " : " << cnt[c - 'a'] << '\n';
	return 0;
}