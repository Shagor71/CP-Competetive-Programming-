#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

int trie_tree[N][26], node = 1, cnt[N][26];

void insert(string s) {
    int next = 0;
    for (auto c : s) {
        if (!trie_tree[next][c - 'a']) trie_tree[next][c - 'a'] = node++;
        next = trie_tree[next][c - 'a'];
        cnt[next][c - 'a']++;
    }
}
//How to search.
int find(string s) {
    int next = 0;
    for (auto c : s) {
        next = trie_tree[next][c - 'a'];
        if (!cnt[next][c - 'a']) return 0;
    }
    return cnt[next][s.back() - 'a'];
}
void solve() {
    int q1, q2;
    cin >> q1 >> q2;

    while (q1--) {
        string s;
        cin >> s;
        insert(s);
    }

    while (q2--) {
        string s;
        cin >> s;
        cout << find(s) << '\n';
    }
}
/*  7
    ace
    adf
    ade
    ad
    bcc
    bc
    bcd

                           noderoot {n = 0, char, ending}
                         /          \
                      /                 \
                   /                        \
                /                               \
             /                                      \
          1a{0, a, 0}                               7b{0, b, 0}
          /              \                            \
        2c{1, c, 0}      4d{1, d, 1}                  8c{7, c, 1}
        /                /          \                 /          \
      3e{2, e, 1}      5f{4, f, 1}  6e{4, e, 1}     9c{8, c, 1} 10d{8, d, 1}
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}