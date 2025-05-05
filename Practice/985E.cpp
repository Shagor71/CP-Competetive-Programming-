#include <bits/stdc++.h>
using namespace std;

/*#define _42_
#ifdef _42_
#include "E:\CP\DBG\debug.h"
#else
#define dbg(...) 42
#endif*/

const int N = 4e5 + 7;

int e;
bool prm[N];
vector<int> prime;
void seive() {
	for (int i = 2; i * i < N; ++i)
		if (!prm[i]) for (int j = i * i; j < N; j += i) prm[j] = 1;
	for (int i = 2; i < N; ++i) prime.push_back(i);
	prm[2] = 1;
	return;
}
void solve() {

	int n; cin >> n;

	vector<int> a(n);
	int cnt = 0, prm_;
	for (auto& i : a) {
		cin >> i;
		cnt += (prm[i] == 0);
		if (!prm[i]) prm_ = i;
	}
	//dbg(cnt)
	//ai - x = p, where p%x == 0 and p - 2 <= ai

	if (cnt > 1 or !cnt) {
		cout << (cnt ? -1 : 2) << '\n';
		return;
	}

	for (auto i : a) {
		//cout << i << ' ';
		int tmp = i, ok = 0;
		if (i % prm_ == 0) continue;
		for (auto dv : prime) {
			if (tmp % dv) continue;
			while (tmp % dv == 0) tmp /= dv;
			int df = i - prm_ * dv;
			if (df < 0) break;
			if ((prm_ * dv) % df == 0 or df % dv == 0) {
				ok = 1;
				break;
			}
		}
		if (!ok) {
			cout << "-1\n";
			return;
		}
	}

	cout << prm_ << '\n';

}
/*


*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	seive();
	int tc; cin >> tc; while (tc--)
		solve();
}