#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<tuple<int, int, int>> t;
	t.push_back(make_tuple(1, 9, 7));

	int d, e, f;
	tie(d, e, f) = t.front();

	cout << d << ' ' << e << ' ' << f;

	return 0;
}