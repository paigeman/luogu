//
// Created by fade on 2023/4/18.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// 时间，草药数量
static int time, nums;
int dfs(int, int, int * [], const int [], const int []);
int main(void)
{
    scanf("%d %d", &time, &nums);
    // 每种草药的价值
    int * value = (int *) malloc(nums * sizeof(int));
    // 采摘每种草药花费的时间
    int * cost = (int *) malloc(nums * sizeof(int));
    for (int i = 0; i < nums; ++i) {
        scanf("%d %d", cost + i, value + i);
    }
//    int * visited = (int *) malloc(nums * sizeof(int));
//    for (int i = 0; i < nums; ++i) {
//        visited[i] = 0;
//    }
    int * dp[nums];
    for (int i = 0; i < nums; ++i) {
        dp[i] = (int *) malloc((time + 1) * sizeof(int));
        for (int j = 0; j <= time; ++j) {
            dp[i][j] = -1;
        }
    }
//    int ans = 0;
//    for (int i = 0; i < nums; ++i) {
//        int result = dfs(i, time, dp, value, cost);
//        if (result > ans) {
//            ans = result;
//        }
//    }
    printf("%d\n", dfs(0, time, dp, value, cost));
    free(value);
    free(cost);
//    free(visited);
    return 0;
}
//int dfs(int pos, int left, int * dp[], const int value[], const int cost[], int visited[]) {
//    // NOTE: 状态方程错了
//    if (dp[pos][left] != -1) {
//        return dp[pos][left];
//    }
//    if (left < cost[pos]) {
//        // 未必代表其它的不能选
//        return (dp[pos][left] = 0);
//    }
//    int ans = 0;
//    visited[pos] = 1;
//    for (int i = 0; i < nums; ++i) {
//        if (!visited[i]) {
//            ans = (int)fmax(ans, dfs(i, left - cost[pos], dp, value, cost, visited));
//        }
//    }
//    visited[pos] = 0;
//    return (dp[pos][left] = ans + value[pos]);
//}
int dfs(int pos, int left, int * dp[], const int value[], const int cost[]) {
    if (pos >= nums) {
        return 0;
    }
    if (dp[pos][left] != -1) {
        return dp[pos][left];
    }
    int ans = dfs(pos + 1, left, dp, value, cost);
    if (left >= cost[pos]) {
        ans = (int) fmax(dfs(pos + 1, left - cost[pos], dp, value, cost) + value[pos], ans);
    }
    return (dp[pos][left] = ans);
}
// TODO 背包解法