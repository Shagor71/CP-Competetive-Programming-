#include <bits/stdc++.h>
using namespace std;

#define _42_
#ifdef _42_
#include "C:\Users\Acer\Documents\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 1e6 + 5, M = 1e9 + 7;

int e;
struct st {
	double x, y;
};
bool ok(st p, vector<st> &v) {
	double j = 0.0;
	for (auto i : v) {
		j++;
		if (i.x * p.x <= p.y * j and p.y * j <= i.y * p.x) continue;
		return 0;
	}
	return 1;
}
int f(double x) {
	return ;
}
double ternary_search(double l, double r) {
	double eps = 1e-9;              //set the error limit here
	while (r - l > eps) {
		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;
		double f1 = f(m1);      //evaluates the function at m1
		double f2 = f(m2);      //evaluates the function at m2
		if (f1 < f2)
			l = m1;
		else
			r = m2;
	}
	return f(l);                    //return the maximum of f(x) in [l, r]
}
void solve() {

	int n; cin >> n;

	vector <st> v;
	st p = {1e6, 1e6}, q = {1e6, 1e6};
	for (int i = 1; i <= n; ++i) {
		double l, r;
		cin >> l >> r;
		if (p.y >= r) p = {(double)i, r};
		if (q.x <= l) q = {(double)i, l};
		v.push_back({l, r});
	}

	cout << "Case #" << ++e << ": ";
	int res = ternary_search(p.x, p.y);
	/*bool ok0[] = {ok(p, v), ok(q, v)};
	if (!(ok0[0] or ok0[1])) {
		cout << "-1\n";
		return;
	}*/
	cout << fixed << setprecision(7) << ((ok0[0] and ok0[1]) ? min(p.x / p.y, q.x / q.y) : ok0[0] ? p.x / p.y : q.x / q.y) << '\n';

}
/*

*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}