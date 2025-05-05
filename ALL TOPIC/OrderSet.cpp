//Problem: https://lightoj.com/problem/diablo
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int n;
	cin >> n;

	o_set<pair<int, int>> se;
	/*se.insert(1);
	se.insert(2);
	se.insert(4);
	se.insert(8);
	se.insert(16);*/

	se.insert({1, 10});
	se.insert({2, 14});
	pair<int, int> rs = *se.find_by_order(0);
	cout << rs.first << ' ' << rs.second << '\n';
	/*//indexe: 0
	cout << *se.find_by_order(0) << '\n'; // 1
	cout << *se.find_by_order(1) << '\n'; // 2
	cout << *se.find_by_order(2) << '\n'; // 4

	cout << se.order_of_key(-5) << '\n'; // 0
	cout << se.order_of_key(4) << '\n'; // 2
	cout << se.order_of_key(7) << '\n'; // 3*/
}
