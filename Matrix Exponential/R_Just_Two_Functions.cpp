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
const int N = 5e5 + 7, MX = N, Mod = 1e6, inf = 1e14;
int e;
int mod;
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
	inline Mat pow(long long k)
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
void solve() {

	int a1, b1, c1, a2, b2, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	int f0, f1, f2, g0, g1, g2;
	cin >> f0 >> f1 >> f2 >> g0 >> g1 >> g2 >> mod;

	vector<vector<int>> mm = {
		{a1, b1, 0, 0, 0, c1},
		{1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 0, c2, a2, b2, 0},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0}
	};

	vector<vector<int>> b = {
		{f2},
		{f1},
		{f0},
		{g2},
		{g1},
		{g0}
	};

	int q; cin >> q;

	while (q--) {
		int n; cin >> n;
		if (n < 3) {
			if (!n) cout << f0 % mod << ' ' << g0 % mod << '\n';
			else if (n == 1) cout << f1 % mod << ' ' << g1 % mod << '\n';
			else cout << f2 % mod << ' ' << g2 % mod << '\n';
			continue;
		}
		Mat res = Mat(mm).pow(n - 2) * Mat(b);

		cout << res.a[0][0] << ' ' << res.a[3][0] << '\n';

	}

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--) {
		cout << "Case " << ++e << ":\n";
		solve();
	}
}