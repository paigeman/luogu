//
// Created by fade on 2023/4/22.
//
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// 总钱数，希望购买的物品个数
static int n, m;
// 主附关系
static unordered_map<int, vector<int>> map;
// 每组物品
static unordered_map<int, vector<vector<int>>> group;
void dfs(int, int, vector<int> *);
int main()
{
    cin >> n >> m;
    // 物品的价格
    int * v = new int[m];
    // 物品的重要度
    int * p = new int[m];
    // 对应主件
    int * q = new int[m];
    int * dp = new int[n + 1];
    // 处理输入
    for (int i = 0; i < m; ++i) {
        cin >> v[i] >> p[i] >> q[i];
        if (q[i]) {
            map[q[i] - 1].push_back(i);
        }
    }
    vector<int> tmp;
    // 处理group
    for (int i = 0; i < m; ++i) {
        if (!q[i]) {
            dfs(0, i, &tmp);
        }
    }
    // 初始化dp
    for (int i = 0; i <= n; ++i) {
        dp[i] = 0;
    }
    for (const auto &kv: group) {
        for (int i = n; i >= 0; --i) {
            for (const auto &j: kv.second) {
                int val = 0;
                int weight = 0;
                for (auto k: j) {
                    val += v[k];
                    weight += v[k] * p[k];
                }
                if (i >= val) {
                    dp[i] = max(dp[i], dp[i - val] + weight);
                }
            }
        }
    }
    cout << dp[n] << endl;
    delete [] q;
    delete [] dp;
    delete [] p;
    delete [] v;
    return 0;
}
void dfs(int index, int p, vector<int> * tmp) {
    if (index >= map[p].size() and tmp->size() < m) {
        vector<int> copy = *tmp;
        copy.push_back(p);
        group[p].push_back(copy);
        return;
    }
    dfs(index + 1, p, tmp);
    (*tmp).push_back(map[p][index]);
    dfs(index + 1, p, tmp);
    (*tmp).pop_back();
}