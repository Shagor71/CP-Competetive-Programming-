#include <bits/stdc++.h>
using namespace std;

int mex(set<int> &se) {
	int i = 0;
	while (!se.empty()) {
		if (i != *se.begin()) return i;
		i++;
		se.erase(se.begin());
	}
	return i;
}

int main() {
	int n;
	cin >> n;

	set<int> se;
	while (n--) {
		int x; cin >> x;
		se.insert(x);
	}
	cout << mex(se) << '\n';
}