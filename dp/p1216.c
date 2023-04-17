//
// Created by fade on 2023/4/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dp(const int, int * []);
int main(void)
{
    int r;
    scanf("%d", &r);
    int * p_ar[r];
    for (int i = 0; i < r; ++i) {
        p_ar[i] = (int *) malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; ++j) {
            scanf("%d", p_ar[i] + j);
        }
    }
    printf("%d\n", dp(r, p_ar));
}
int dp(const int r, int * p_ar[]) {
    int * status = (int *) malloc(r * sizeof(int));
    // 初始化
    for (int i = 0; i < r; ++i) {
        *(status + i) = 0;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = i; j >= 0; --j) {
            if (j > 0) {
                *(status + j) = (int) fmax(*(status + j), *(status + j - 1)) + *(p_ar[i] + j);
            } else {
                *(status + j) = *(p_ar[i] + j) + *(status + j);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < r; ++i) {
        if (ans < *(status + i)) {
            ans = *(status + i);
        }
    }
    return ans;
}