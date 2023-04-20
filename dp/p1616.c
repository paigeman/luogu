//
// Created by fade on 2023/4/19.
//
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a>b)?(a):(b))
// 采药的时间，草药的种类
static int t, m;
int main(void)
{
    scanf("%d %d", &t, &m);
    // 采药耗时
    int * a = (int *) malloc(m * sizeof(int));
    // 价值
    int * b = (int *) malloc(m * sizeof(int));
    long long int * dp = (long long int *) malloc((t + 1) * sizeof(long long int));
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", a + i, b + i);
    }
    for (int i = 1; i <= t; ++i) {
        *(dp + i) = 0;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = a[i]; j <= t; ++j) {
            *(dp + j) = max(*(dp + j), *(dp + j - *(a + i)) + *(b + i));
//            long long int tmp = *(dp + j - *(a + i)) + *(b + i);
//            if (*(dp + j) < tmp) {
//                *(dp + j) = tmp;
//            }
        }
    }
    printf("%lld\n", *(dp + t));
    free(dp);
    free(b);
    free(a);
    return 0;
}