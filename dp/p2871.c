//
// Created by fade on 2023/4/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 物品个数，背包大小
static int n, m;
int main(void)
{
    scanf("%d %d", &n, &m);
    int * w = (int *) malloc(n * sizeof(int));
    int * d = (int *) malloc(n * sizeof(int));
    int * dp = (int *) malloc(m * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", w + i, d + i);
    }
    for (int i = 0; i < m; ++i) {
        *(dp + i) = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= w[i] - 1; --j) {
            *(dp + j) = (int) fmax(*(dp + j), *(dp + j - w[i]) + *(d + i));
        }
    }
    printf("%d\n", *(dp + m - 1));
    return 0;
}