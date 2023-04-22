//
// Created by fade on 2023/4/21.
//
#include <stdlib.h>
#include <stdio.h>
#define max(a,b) ((a>b)?(a):(b))
int main(void)
{
    // n个愿望，M元钱，T分钟时间
    int n, M, T;
    scanf("%d %d %d", &n, &M, &T);
    // 第i个愿望所需要的金钱
    int * m = (int *) malloc(n * sizeof(int));
    // 第i个愿望所需要的时间
    int * t = (int *) malloc(n * sizeof(int));
    int (* dp)[T + 1] = (int (*) [])malloc((M + 1) * (T + 1) * sizeof(int));
    // 处理输入
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", m + i, t + i);
    }
    // 初始化dp
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= T; ++j) {
            *(*(dp + i) + j) = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = M; j >= *(m + i); --j) {
            for (int k = T; k >= *(t + i); --k) {
                *(*(dp + j) + k) = max(*(*(dp + j) + k), *(*(dp + j - *(m + i)) + k - *(t + i)) + 1);
            }
        }
    }
    printf("%d\n", *(*(dp + M) + T));
    free(dp);
    free(t);
    free(m);
    return 0;
}