#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int unsigned long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

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
				ans.a[i][j] = (a[i][j] + b.a[i][j]);
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
				ans.a[i][j] = (a[i][j] - b.a[i][j]);
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
					ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j]);
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

	int p, q, n;
	cin >> p >> q >> n;

	if (!n) {
		cout << "Case " << ++e << ": " << (n ? p : 2) << '\n';
		return;
	}

	n -= 1;
	vector<vector<int>> A = {
		{p, -q},
		{1, 0}
	};
	vector < vector<int>> B = {
		{p},
		{2},
	};


	cout << "Case " << ++e << ": " << (Mat(A).pow(n) * Mat(B)).a[0][0] << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc; while (tc--)
		solve();
}