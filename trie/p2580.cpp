//
// Created by fade on 2024/1/28.
//
#include <iostream>
#include <string>

class Trie {
    int next[500000][26];
    int cnt;
    int exist[500000];
public:
    void insert(const std::string & s) {
        int p = 0;
        for (const char & c: s) {
            int po = c - 'a';
            if (!next[p][po]) {
                next[p][po] = ++cnt;
            }
            p = next[p][po];
        }
        exist[p] = 1;
    }
    int find(const std::string & s) {
        int p = 0;
        for (const char & c: s) {
            int po = c - 'a';
            if (!next[p][po]) {
                return 0;
            }
            p = next[p][po];
        }
        return exist[p]++;
    }
};


int main()
{
    int n, m;
    Trie trie{};
    using namespace std;
    cin >> n;
    string an;
    for (size_t i = 0; i < n; ++i) {
        cin >> an;
        trie.insert(an);
    }
    cin >> m;
    string sa[m];
    for (size_t i = 0; i < m; ++i) {
        cin >> sa[i];
    }
    for (const string & s: sa) {
        int res = trie.find(s);
        if (res == 1) {
            cout << "OK" << endl;
        }
        else if (res > 1) {
            cout << "REPEAT" << endl;
        }
        else {
            cout << "WRONG" << endl;
        }
    }
    return 0;
}