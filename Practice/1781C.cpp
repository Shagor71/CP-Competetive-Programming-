#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
const int N = 2e5 + 7, M = 998244353;

void solve() {

	int n;
	string s;
	cin >> n >> s;

	map<char, int> m;
	for (auto c : s) m[c]++;

	vector<pair<int, char>> tch, hc;
	for (char c = 'a'; c <= 'z'; c++) tch.push_back({m[c], c});

	sort(tch.rbegin(), tch.rend());
	//dbg(tch);
	int best_cost = n + 37;
	string res;
	auto cal = [&](int need) {
		vector<pair<int, char>> ch = tch;
		string t = s, a, b;
		int cost = 0;
		for (auto &[fq, c] : ch)
			for (auto &cc : t) if (cc == c and fq > need) cc = '$', fq--, cost++;
		//a = t;
		for (auto &[fq, c] : ch)
			for (auto &cc : t) if (cc == '$' and fq < need) cc = c, fq++;
		//b = t;
		sort(ch.rbegin(), ch.rend());
		vector<pair<int, char>> hc = ch;
		reverse(hc.begin(), hc.end());
		map<char, int> mm;
		for (auto [fq, c] : ch) mm[c] = fq;

		for (auto [fq, c] : ch)
			for (auto [fq1, c1] : hc)
				for (auto &cc : t)
					if (c1 == cc and mm[c] and mm[c] < need  and mm[cc] and mm[cc] < need)
						cc = c, mm[c]++, mm[c1]--, cost++;

		//dbg(cost, need, a, b, t);

		if (cost < best_cost) best_cost = cost, res = t;
	};

	for (int d = 1; d <= min(26ll, n); ++d) if (n % d == 0) cal(n / d);

	cout << best_cost << '\n' << res << '\n';
}
/*
	appalk
	appaap
	a = 2
	p = 2
	l = 1
	k = 1

	6
	aaaabbbccdde
	aaacbbbccddd

	a = 3
	b = 3
	c = 2
	d = 2
	e = 1

	need: 3
	se[] = {(1, a)}
	c: {(1, a)} erase->se->end
	d: {}
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}