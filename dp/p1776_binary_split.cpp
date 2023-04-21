//
// Created by fade on 2023/4/21.
//
#include <iostream>
#include <vector>
#define max(a,b) ((a>b)?(a):(b))
int main()
{
    using namespace std;
    // n种宝物，最大载重W
    static int n, W;
    cin >> n >> W;
    // 每种宝物的价值vi
    vector<int> v;
    // 每种宝物的重量wi
    vector<int> w;
    int * dp = new int[W + 1];
    for (int i = 0; i < n; ++i) {
        int tv, tw, tm;
        cin >> tv >> tw >> tm;
        for (int j = 1; j <= tm; j <<= 1) {
            v.push_back(tv * j);
            w.push_back(tw * j);
            tm -= j;
        }
        if (tm) {
            v.push_back(tv * tm);
            w.push_back(tw * tm);
        }
    }
    for (int i = 0; i <= W; ++i) {
        *(dp + i) = 0;
    }
    // 0-1 背包
    for (int i = 0; i < v.size(); ++i) {
        for (int j = W; j >= w[i]; --j) {
            *(dp + j) = max(*(dp + j), *(dp + j - w[i]) + v[i]);
        }
    }
    cout << (*(dp + W)) << endl;
    delete [] dp;
    return 0;
}