//
// Created by fade on 2023/4/22.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
int main()
{
    using namespace std;
    // n件物品，总重量为m
    int n, m;
    cin >> m >> n;
    // 物品的重量
    int * a = new int[n];
    // 利用价值
    int * b = new int[n];
    // 每组物品
    unordered_map<int, vector<int>> map;
    int * dp = new int[m + 1];
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> *(a + i) >> *(b + i) >> c;
        map[c].push_back(i);
    }
    // 初始化dp
    for (int i = 0; i <= m; ++i) {
        dp[i] = 0;
    }
    // 动态规划
    for (const auto &kv: map) {
        for (int i = m; i >= 0; --i) {
            for (auto j: kv.second) {
                if (i >= a[j]) {
                    dp[i] = max(dp[i], dp[i - a[j]] + b[j]);
                }
            }
        }
    }
    cout << dp[m] << endl;
    delete [] dp;
    delete [] b;
    delete [] a;
    return 0;
}