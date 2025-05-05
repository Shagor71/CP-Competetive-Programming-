#include <bits/stdc++.h>
using namespace std;

struct st {
    int x, y, z;
};
struct cmp {
    bool operator() (st a, st b) {
        if (a.x == b.x) return (a.y == b.y ? a.z > b.z : a.z <= b.z);
        return a.x > b.x;
    }
};

int main() {
    int n; cin >> n;

    priority_queue<st , vector<st>, cmp> pq;
    for (int i = 1; i <= n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        pq.push({x, y, z});
    }

    while (!pq.empty()) {
        st p = pq.top();
        pq.pop();
        cout << p.x << ' ' << p.y << ' ' << p.z << '\n';
    }
}