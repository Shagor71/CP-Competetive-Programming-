#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
#define MAT vector<vector<int>>
const int N = 2e5 + 7, MX = N, Mod = 1e9 + 7, inf = 1e9;
int e;
int mod = Mod;

struct Mat
{
	int n, m;
	vector<vector<int>> a;
	Mat() {}
	Mat(int _n, int _m)
	{
		n = _n;
		m = _m;
		a.assign(n, vector<int>(m, 0));
	}
	Mat(vector<vector<int>> v)
	{
		n = v.size();
		m = n ? v[0].size() : 0;
		a = v;
	}
	inline void make_unit()
	{
		assert(n == m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				a[i][j] = i == j;
		}
	}
	inline Mat operator+(const Mat &b)
	{
		assert(n == b.n && m == b.m);
		Mat ans = Mat(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
			}
		}
		return ans;
	}
	inline Mat operator-(const Mat &b)
	{
		assert(n == b.n && m == b.m);
		Mat ans = Mat(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
			}
		}
		return ans;
	}
	inline Mat operator*(const Mat &b)
	{
		assert(m == b.n);
		Mat ans = Mat(n, b.m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < b.m; j++)
			{
				for (int k = 0; k < m; k++)
				{
					ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
				}
			}
		}
		return ans;
	}
	inline Mat exp(long long k)
	{
		assert(n == m);
		Mat ans(n, n), t = a;
		ans.make_unit();
		while (k)
		{
			if (k & 1)
				ans = ans * t;
			t = t * t;
			k >>= 1;
		}
		return ans;
	}
	inline Mat &operator+=(const Mat &b) { return *this = (*this) + b; }
	inline Mat &operator-=(const Mat &b) { return *this = (*this) - b; }
	inline Mat &operator*=(const Mat &b) { return *this = (*this) * b; }
	inline bool operator==(const Mat &b) { return a == b.a; }
	inline bool operator!=(const Mat &b) { return a != b.a; }
};
MAT M = {
	{1, 1},
	{1, 0}
};
MAT B = {
	{0},
	{1}
};
MAT I = {
	{1, 0},
	{0, 1}
};

Mat res[3 * N];
vector<int> a(N);
void build(int node, int l, int r) {
	if (l == r) {
		res[node] = Mat(M).exp(a[l]) + Mat(I);
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m), build(node << 1 | 1, m + 1, r);
	res[node] = Mat(res[node << 1]) * Mat(res[node << 1 | 1]);
}
void update(int node, int l, int r, int pos) {
	if (l == r) {
		res[node] = Mat(M).exp(a[l]) + Mat(I);
		return;
	}
	int m = l + r >> 1;
	pos <= m ? update(node << 1, l, m, pos) : update(node << 1 | 1, m + 1, r, pos);
	res[node] = Mat(res[node << 1]) * Mat(res[node << 1 | 1]);
}
Mat query(int node, int l, int r, int fl, int fr) {
	if (fl <= l and r <= fr) return res[node];
	if (r < fl or fr < l) return I;
	int m = l + r >> 1;
	return query(node << 1, l, m, fl, fr) * query(node << 1 | 1, m + 1, r, fl, fr);
}
void solve() {

	int n, q;
	cin >> n >> q;

	a.resize(n);
	for (auto& i : a) cin >> i;
	build(1, 0, n - 1);

	while (q--) {
		char t; cin >> t;
		if (t == 'Q') {
			int l, r;
			cin >> l >> r;
			Mat ans = Mat(query(1, 0, n - 1, l - 1, r - 1)) - Mat(I);
			ans = Mat(ans) * Mat(B);
			cout << ans.a[0][0] << '\n';
			continue;
		}
		int i, x;
		cin >> i >> x;
		a[i - 1] = x;
		update(1, 0, n - 1, i - 1);
	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}