#include <stdio.h>

int Dp[2][501][501];

int main()
{
    int N, M, b, Mod, i, j, k;
    int A[501];
    scanf("%d %d %d %d", &N, &M, &b, &Mod);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    Dp[1][0][0] = 1;
    for(i = 0; i < N; ++i) {
        int it = i & 1;
        for(j = 0; j <= M; ++j) {
            for(k = 0; k <= b; ++k) {
                Dp[it][j][k] = Dp[it ^ 1][j][k];
                if(j >= 1 && k >= A[i]) {
                    Dp[it][j][k] += Dp[it][j - 1][k - A[i]];
                    if(Dp[it][j][k] >= Mod) {
                        Dp[it][j][k] -= Mod;
                    }
                }
            }
        }
    }
    int Ans = 0;
    for(i = 0; i <= b; ++i) {
        Ans += Dp[(N - 1) & 1][M][i];
        if(Ans >= Mod) {
            Ans -= Mod;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
