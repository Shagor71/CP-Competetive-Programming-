//https://vjudge.net/contest/659523#problem/G
//https://atcoder.jp/contests/abc242/tasks/abc242_g?lang=en
#include <bits/stdc++.h>
using namespace std;
/*
#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/

#define ll long long
const int N = 1e5 + 7;

int sq;
struct G {
	int i, l, r;
};

bool comp(G a, G b) {
	return (a.l / sq == b.l / sq ? (a.r > b.r) : (a.l / sq < b.l / sq));
}

int cnt[N];

int add(int x) {
	cnt[x] ^= 1;
	return cnt[x] == 0;
}
int rmv(int x) {
	cnt[x] ^= 1;
	return cnt[x] == 1;
}
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	for (auto &i : a) cin >> i;

	int q; cin >> q;

	vector<G> qe(q);
	int j = 0;
	for (auto &[i, l, r] : qe) {
		cin >> l >> r;
		i = j++;
	}

	sq = sqrtl(n);
	sort(qe.begin(), qe.end(), comp);

	vector<int> res(q);
	int tl = 0, tr = -1, rs = 0;
	for (auto [i, l, r] : qe) {
		l--, r--;
		while (tl < l) rs -= rmv(a[tl++]);
		while (l < tl) rs += add(a[--tl]);
		while (tr < r) rs += add(a[++tr]);
		while (r < tr) rs -= rmv(a[tr--]);
		res[i] = rs;
	}

	for (auto i : res) cout << i << '\n';

}
/*


*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}