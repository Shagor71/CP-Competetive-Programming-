#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif


void solve() {
	int q; cin >> q;

	deque<int> dq;
	bool ok = 1;
	while (q--) {
		string s;
		cin >> s;
		if (s == "toFront" or s == "push_back") {
			int x; cin >> x;
			if (ok) s == "toFront" ? dq.push_front(x) : dq.push_back(x);
			else s == "push_back" ? dq.push_front(x) : dq.push_back(x);
		} else {
			if (s == "reverse") ok = 1 - ok;
			if (s == "back" or s == "front") {
				if (dq.empty()) cout << "No job for Ada?\n";
				else {
					if (ok) {
						cout << (s == "front" ? dq.front() : dq.back()) << '\n';
						s == "front" ? dq.pop_front() : dq.pop_back();
					}
					else {
						cout << (s == "front" ? dq.back() : dq.front()) << '\n';
						s == "back" ? dq.pop_front() : dq.pop_back();
					}
				}
			}
		}
	}
}
/*


*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}