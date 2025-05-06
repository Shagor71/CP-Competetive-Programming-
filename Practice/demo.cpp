#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _42_
#ifdef _42_
#include "D:\CP\debug.h"
#else
#define dbg(...) 42
#endif

#define int long long
#define mk make_pair
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

vector<int> buildArray(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		int x = i;
		cout << i << '\n';
		while (x >= 0 and nums[x] >= 0 and nums[x] != x) {
			int a = nums[x], b = nums[a];
			nums[x] = -b, nums[a] = a;
			x = b;
			cout << a << ' ' << b << ' ' << x << '\n';
			dbg(nums);
		}
	}
	for (auto& i : nums) cout << i << ' ';
	return nums;
}
void solve() {

	int n; cin >> n;
	vector<int> nums(n);
	for (auto& i : nums) cin >> i;

	buildArray(nums);

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}