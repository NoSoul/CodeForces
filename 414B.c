#include <stdio.h>
#include <string.h>

#define MOD 1000000007
int Origin[2001];
int Dp[2][2001];

int main()
{
    int N, K, Cur = 0, Ans, i, j, k;
    scanf("%d %d", &N, &K);
    for(i = 1; i <= N; ++i) {
        Dp[Cur][i] = 1;
    }
    for(k = 1; k < K; ++k) {
        for(i = 1; i <= N; ++i) {
            Dp[Cur ^ 1][i] = 1;
        }
        for(i = 2; i <= N; ++i) {
            for(j = i; j <= N; j += i) {
                Dp[Cur ^ 1][j] += Dp[Cur][i];
                Dp[Cur ^ 1][j] %= MOD;
            }
        }
        Cur ^= 1;
    }
    Ans = 0;
    for(i = 1; i <= N; ++i) {
        Ans += Dp[Cur][i];
        Ans %= MOD;
    }
    printf("%d\n", Ans);
    return 0;
}
