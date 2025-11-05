//https://lightoj.com/problem/maximum-subset-sum
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    map<string, int> mp, m;
    int i = 1;
    for (auto s : wordlist) {
        mp[s] = 1;
        string ns;
        for (auto c : s) {
            if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
                ns += '#';
            else if ('A' <= c and c <= 'Z') {
                char ch = c + 32;
                ns += ch;
            }
            else
                ns += c;
        }
        m[ns] = i++;
    }
    vector<string> res;
    for (auto s : queries) {
        if (mp[s]) {
            res.push_back(s);
            continue;
        }
        string ns;
        for (auto c : s) {
            if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
                ns += '#';
            else if ('A' <= c and c <= 'Z') {
                char ch = c + 32;
                ns += ch;
            }
            else
                ns += c;
        }
        if (mp[ns]) {
            res.push_back(wordlist[mp[ns] - 1]);
            continue;
        }
        res.push_back("");
    }
    return res;
}
int main() {
    vector<string> a(1), b(1);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    spellchecker(a, b);

}