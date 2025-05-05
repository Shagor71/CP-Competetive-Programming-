#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 5;
int par[MAX];
int ask(int a, int b) {
	cout << "? " << a << ' ' << b << endl;
	int x;
	cin >> x;
	return x;
}
void calc(int a, int b) {
	if (a == b) return ;
	if (par[b]) return;
	int x = ask(a, b);
	if (x == a) {
		par[b] = a;
		return ;
	}
	calc(a, x);
	calc(x, b);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) par[i] = 0;
	for (int i = 1; i <= n; i++) if (!par[i]) calc(1, i);
	cout << "!";
	for (int i = 2; i <= n; i++) cout << ' ' << i << ' ' << par[i];
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}