#include <bits/stdc++.h>
using namespace std;

//#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define ll long long
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
int res[50];
void solve() {

    int t, k, n;
    cin >> t >> k >> n;

    if (!t and !n) {
        cout << "0\n";
        return;
    }

    MAT MM = {
        {1 + k, 0},
        {1, 0}
    };
    MAT BB = {
        {1},
        {1}
    };

    if (n < t) {
        cout << (!n ? 1 : (Mat(MM).exp(n) * Mat(BB)).a[0][0]) << '\n';
        return;
    }

    Mat M = Mat(t + 1, t + 1), B = Mat(t + 1, t + 1);
    for (int i = 0; i <= t; ++i) {
        for (int j = 0; j <= t; ++j) {
            if (i) M.a[i][j] = (i - 1 == j);
            else {
                if (!j) M.a[i][j] = 1 + k;
                else M.a[i][j] = (j == t ? -1 : 0);
            }
        }
    }

    B.a[t][0] = B.a[t - 1][0] = 1;
    int val = 1;

    for (int i = 2; i <= t; ++i) B.a[t - i][0] = val = val * (k + 1);
    for (int i = 0; i <= t; ++i) {
        cout << B.a[i][0] << '\n';
        //for (int j = 0; j <= t; ++j) cout << M.a[i][j] << " \n"[j == t];
    }

    Mat A = Mat(M).exp(n - 3 + 1);
    for (int i = 0; i <= t; ++i)
        for (int j = 0; j <= t; ++j) cout << A.a[i][j] << " \n"[j == t];
    cout << (Mat(M).exp(n - 3 + 1) * Mat(B)).a[0][0] << '\n';
}
/*


*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--)
        solve();
}