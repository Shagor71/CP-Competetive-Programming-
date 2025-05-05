#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif
*/
//#define int long long
const int N = 1e2 + 5, M = 1e9 + 7;

int dp[N];

void solve() {

	string s;
	cin >> s;

	stack<char> st;

	map<char, int> m;
	for (auto i : s) {
		if (i == '(') st.push('(');
		else if (i == ')') {
			while (st.top() != '(') m[st.top()]--, st.pop();
			st.pop();
		}
		else {
			if (m[i]) {
				cout << "No\n";
				return;
			}
			m[i]++;
			st.push(i);
		}
	}

	cout << "Yes\n";

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}