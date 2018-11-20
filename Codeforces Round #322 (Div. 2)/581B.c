#include <stdio.h>
#include <math.h>
#define MAXN    100001
typedef int DataType_t;
int Dp[MAXN][20];
DataType_t Src[MAXN];

int FunCmp(DataType_t *src, int x, int y)
{
    if(src[x] > src[y]) {
        return 1;
    }
    if(src[x] < src[y]) {
        return 0;
    }
    return x < y ? 1 : 0;
}

void SetSTRMQ(int dp[MAXN][20], DataType_t *src, int n, int (*fun)(DataType_t *, int, int))
{
    int i, j, k;
    for(i = 0; i < n; ++i) {
        dp[i][0] = i;
    }
    k = log2(n);
    for(j = 1; j <= k; ++j) {
        for(i = 0; i + (1 << j) - 1 < n; ++i) {
            dp[i][j] = fun(src, dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]) ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
        }
    }
}

DataType_t GetSTRMQ(int dp[MAXN][20], DataType_t *src, int a, int b, int (*fun)(DataType_t *, int, int))
{
    int k = log2(b - a + 1);
    int resid = fun(src, dp[a][k], dp[b - (1 << k) + 1][k]) ? dp[a][k] : dp[b - (1 << k) + 1][k];
    return src[resid];
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Src[i]);
    }
    SetSTRMQ(Dp, Src, N, FunCmp);
    for(i = 0; i < N - 1; ++i) {
        int target = GetSTRMQ(Dp, Src, i + 1, N - 1, FunCmp);
        if(Src[i] > target) {
            printf("0 ");
        } else {
            printf("%d ", target + 1 - Src[i]);
        }
    }
    puts("0");
    return 0;
}
