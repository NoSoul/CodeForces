#include <stdio.h>
#include <math.h>

int A[200000];
long long B[200000];
int Dp[200000][20];

void SetRMQ(long long *array, int n)
{
    int i, j, k;
    for(i = 0; i < n; ++i) {
        Dp[i][0] = i;
    }
    k = log(n) / log(2);
    for(j = 1; j <= k; ++j) {
        for(i = 0; i + (1 << j) - 1 < n; ++i) {
            if(array[Dp[i][j - 1]] > array[Dp[i + (1 << (j - 1))][j - 1]]) {
                Dp[i][j] = Dp[i][j - 1];
                continue;
            }
            if(array[Dp[i][j - 1]] == array[Dp[i + (1 << (j - 1))][j - 1]]) {
                Dp[i][j] = Dp[i][j - 1] < Dp[i + (1 << (j - 1))][j - 1] ?
                           Dp[i][j - 1] : Dp[i + (1 << (j - 1))][j - 1];
                continue;
            }
            if(array[Dp[i][j - 1]] < array[Dp[i + (1 << (j - 1))][j - 1]]) {
                Dp[i][j] = Dp[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int GetRMQ(long long *array, int a, int b)
{
    int k = log(b - a + 1) / log(2);
    if(array[Dp[a][k]] > array[Dp[b - (1 << k) + 1][k]]) {
        return Dp[a][k];
    }
    if(array[Dp[a][k]] < array[Dp[b - (1 << k) + 1][k]]) {
        return Dp[b - (1 << k) + 1][k];
    } else {
        return Dp[a][k] < Dp[b - (1 << k) + 1][k] ?
               Dp[a][k] : Dp[b - (1 << k) + 1][k];
    }
}

int main()
{
    int N, K, i, L;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    B[0] = 0;
    for(i = 0; i < K; ++i) {
        B[0] += A[i];
    }
    for(i = 1; i + K <= N; ++i) {
        B[i] = B[i - 1] - A[i - 1] + A[i + K - 1];
    }
    SetRMQ(B, N - K + 1);
    long long Max = 0;
    int MinA, MinB;
    for(i = 0; i + K <= N - K; ++i) {
        int cura = i;
        int curb = GetRMQ(B, i + K, N - K);
        if(B[cura] + B[curb] > Max) {
            Max = B[i] + B[curb];
            MinA = cura;
            MinB = curb;
        } else if(B[cura] + B[curb] == Max) {
            if((cura < MinA) || (cura == MinA && curb < MinB)) {
                MinA = cura;
                MinB = curb;
            }
        }
    }
    printf("%d %d\n", MinA + 1, MinB + 1);
    return 0;
}
