#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl<<flush;
#define endl '\n'
#define INF 1e17
const ll M = 998244353;
const ll N = 1e6 + 1;
const ll LOG = 11;
void debug(vector<ll> v) {for (auto it : v) {cout << it << " ";} cout << endl;}
ll n, m;
int32_t main()
{
	fast
	ll i, j = 1, k, p, q, tc = 1, cs = 0;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		vector<ll>a(n + 1), b(n + 1), c;
		for (i = 1; i <= n; i++) {cin >> a[i];}
		for (i = 1; i <= n; i++) {cin >> b[i];}
		ll possible = 1;
		c = a;
		for (i = 1; i <= n; i++)
		{
			if (a[i] == b[i]) {continue;}
			if (a[i - 1] == b[i]) {a[i] = b[i]; continue;}

			for (j = i + 1; j <= n; j++)
			{
				if (a[j] == b[i]) {break;}
			}
			if (j == n + 1) {break;}
			for (k = i; k <= j; k++)
			{
				a[k] = b[i];
			}
		}
		if (a == b)
		{
			cout << "YES" << endl; continue;
		}

		c.pb(0);
		b.pb(0);
		reverse(c.begin(), c.end());
		reverse(b.begin(), b.end());
		c.pop_back();
		b.pop_back();
		for (i = 1; i <= n; i++)
		{
			if (c[i] == b[i]) {continue;}
			if (c[i - 1] == b[i]) {c[i] = b[i]; continue;}

			for (j = i + 1; j <= n; j++)
			{
				if (c[j] == b[i]) {break;}
			}
			if (j == n + 1) {break;}
			for (k = i; k <= j; k++)
			{
				c[k] = b[i];
			}
		}
		if (c == b) {cout << "YES" << endl; continue;}
		cout << "NO" << endl;
	}
}
