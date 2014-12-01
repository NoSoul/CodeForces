#include <stdio.h>

#define max(x, y) ((x)>(y)?(x):(y))
long long P[5001];
long long Dp[5001][5001];
long long Ans;

int main()
{
    int N, M, K, i, j;
    scanf("%d %d %d", &N, &M, &K);
    for(i = 1; i <= N; ++i)
    {
        scanf("%d", &P[i]);
        P[i] += P[i - 1];
    }
    for(i = 1; i <= N; ++i)
    {
        for(j = 1; j <= K; ++j)
        {
            if(i < M)
            {
                Dp[i][j] = Dp[i - 1][j];
            }
            else
            {
                Dp[i][j] = max(Dp[i - 1][j], Dp[i - M][j - 1] + P[i] - P[i - M]);
            }
            Ans = max(Ans, Dp[i][j]);
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
