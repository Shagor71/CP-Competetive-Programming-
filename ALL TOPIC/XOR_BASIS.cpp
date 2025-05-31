//https://lightoj.com/problem/maximum-subset-sum
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void insert(vector<ll>&basis, ll mask) {
    for(int i = 63; i >= 0; --i) 
        if((mask & 1ll << i)) {
            if(!basis[i]) {
                basis[i] = mask;
                return;
            }
            mask ^= basis[i];
        }
    return;
}
int main() {
    int n; cin >> n;
    
    vector<ll> basis(65, 0);
    for(int i = 0; i < n; ++i) {
        ll mask; cin >> mask;
        insert(basis, mask);
    }
    for(auto i : basis) 
        if(i) cout << i << ' '; 
}