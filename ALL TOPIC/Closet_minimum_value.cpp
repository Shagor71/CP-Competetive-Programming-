#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> lst(n);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	vector<int> lmin(n);
	lmin[n - 1] = n;
	for (int i = n - 2; i >= 0; i--) {
		int j = i + 1;
		while (j < n && lst[j] >= lst[i]) {
			j = lmin[j];
			lmin[i] = j;
		}
		lmin[i] = j;
	}
	/*stack<pair<int, int>> st;
	for (int i = n; i; --i) {
		while (!st.empty() and st.top().first >= lst[i])
			lmin[i] = max(lmin[i], lmin[st.top().second]), st.pop();
		st.push({lst[i], i});
	}*/
	for (int i = 0; i < n; i++)  cout << lmin[i] << ' ';
}
/*
8
3 2 1 2 3 2 4 1
1 2 8 7 5 7 7 8
*/