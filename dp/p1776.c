//
// Created by fade on 2023/4/20.
//
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a>b)?(a):(b))
// n种宝物，最大载重W
static int n, W;
// 每种宝物的价值vi
static int * v;
// 每种宝物的重量wi
static int * w;
// 每种宝物有多少件mi
static int * m;
int main(void)
{
    scanf("%d %d", &n, &W);
    v = (int *) malloc(n * sizeof(int));
    w = (int *) malloc(n * sizeof(int));
    m = (int *) malloc(n * sizeof(int));
    int * dp = (int *) malloc((W + 1) * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", v + i, w + i, m + i);
    }
    for (int i = 0; i <= W; ++i) {
        *(dp + i) = 0;
    }
    for (int i = 0; i < n; ++i) {
//        for (int j = 1; j <= *(m + i); ++j) {
//            int low_bound = j * (*(w + i));
//            int val = ((*(v + i)) * j);
//            if (low_bound > W) {
//                break;
//            }
//            for (int k = W; k >= low_bound; --k) {
//                *(dp + k) = max(*(dp + k), (*(dp + k - low_bound)) + val);
//            }
//        }
        for (int j = W; j >= *(w + i) ; --j) {
            for (int k = 1; k <= *(m + i); ++k) {
                int p = j - k * (*(w + i));
                int val = k * (*(v + i));
                if (p >= 0) {
                    *(dp + j) = max(*(dp + j), *(dp + p) + val);
                } else {
                    break;
                }
            }
        }
    }
    printf("%d\n", *(dp + W));
    free(dp);
    free(m);
    free(w);
    free(v);
    return 0;
}