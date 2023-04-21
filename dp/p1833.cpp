//
// Created by fade on 2023/4/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    using namespace std;
    // 现在时间
    string ts;
    // 去上学时间
    string te;
    // n课樱花树
    int n;
    cin >> ts >> te >> n;
    // 是否是完全背包
    vector<bool> is_complete;
    // 每棵树的耗费时间
    vector<int> T;
    // 美学值
    vector<int> C;
    // 处理输入
    for (int i = 0; i < n; ++i) {
        int t, c, p;
        cin >> t >> c >> p;
        if (p) {
            for (int j = 1; j <= p; j <<= 1) {
                T.push_back(t * j);
                C.push_back(c * j);
                is_complete.push_back(false);
                p -= j;
            }
            if (p) {
                T.push_back(t * p);
                C.push_back(c * p);
                is_complete.push_back(false);
            }
        } else {
            is_complete.push_back(true);
            T.push_back(t);
            C.push_back(c);
        }
    }
    // 处理时间
    auto p1 = ts.find(':');
    int h1 = stoi(ts.substr(0, p1));
    int m1 = stoi(ts.substr(p1 + 1));
    auto p2 = te.find(':');
    int h2 = stoi(te.substr(0, p2));
    int m2 = stoi(te.substr(p2 + 1));
    int tm = h2 * 60 + m2 - h1 * 60 - m1;
    int * dp = new int[tm + 1];
    for (int i = 0; i <= tm; ++i) {
        *(dp + i) = 0;
    }
    for (int i = 0; i < T.size(); ++i) {
        if (is_complete[i]) {
            for (int j = T[i]; j <= tm; ++j) {
                *(dp + j) = max(*(dp + j), *(dp + j - T[i]) + C[i]);
            }
        } else {
            for (int j = tm; j >= T[i]; --j) {
                *(dp + j) = max(*(dp + j), *(dp + j - T[i]) + C[i]);
            }
        }
    }
    cout << *(dp + tm) << endl;
    delete [] dp;
    return 0;
}