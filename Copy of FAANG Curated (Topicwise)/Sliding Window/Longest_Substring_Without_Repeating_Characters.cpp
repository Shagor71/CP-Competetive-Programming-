#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

int lengthOfLongestSubstring(string s) {
    map<int, int> cnt;
    int res = 0;
    for(int i = 0, j = 0; i < s.size(); ++i) {
        cnt[s[i] - 'a']++;
        while(j < i and cnt[s[i]-'a'] > 1) cnt[s[j] - 'a']--, j++;
        res = max(res, i - j + 1);
    }
    return res;
}
void solve() {
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s) << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int tc; cin >> tc; while (tc--)
        solve();
}