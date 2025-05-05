#include <bits/stdc++.h>
using namespace std;


#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;
int path[N];

struct st {
	double x, y;
};
st coordinate(st A, double r, double theta) {
	double x = r * cos(theta);
	double y = r * sin(theta);
	return {x + A.x, y + A.y};
}
void solve() {
	st A, B;
	int d;

	cin >> B.x >> B.y >> A.x >> A.y >> d;

	B.x -= A.x;
	B.y -= A.y;

	double r = sqrt(B.x * B.x + B.y * B.y);
	double theta = acos(2.0 * r * r - d * d / (2.0 * r * r));


	st P = coordinate(A, r, theta);
	st Q = coordinate(A, r, -theta);

	cout << setprecision(10) << fixed << P.x << ' ' << P.y << ' ' << Q.x << ' ' << Q.y << '\n';

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}