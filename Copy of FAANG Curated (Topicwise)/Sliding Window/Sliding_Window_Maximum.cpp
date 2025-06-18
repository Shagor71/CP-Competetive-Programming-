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
const int N = 2e5 + 7, MX = N, M = 1e9 + 7;
int e;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	deque<int> dq;
	int n = nums.size();
	vector<int> res;
	for (int i = 0, j = 0; i < n; ++i) {
		if (!dq.empty() and dq.front() == i - k) dq.pop_front();
		while (!dq.empty() and nums[dq.back()] <= nums[i]) dq.pop_back();
		dq.push_back(i);
		if (i >= k - 1)
			res.push_back(nums[dq.front()]);
	}
	return res;
}
void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	maxSlidingWindow(a, k);

}
/*


*/
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tc; cin >> tc; while (tc--)
	solve();
}