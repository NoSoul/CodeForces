#include <stdio.h>

#define MOD 1000000007

long long Dp[100001];

int main()
{
    int T, K, i;
    scanf("%d %d", &T, &K);
    Dp[0] = 1;
    for(i = 1; i < 100001; ++i) {
        Dp[i] = Dp[i - 1];
        if(i >= K) {
            Dp[i] += Dp[i - K];
            Dp[i] %= MOD;
        }
    }
    for(i = 2; i < 100001; ++i) {
        Dp[i] += Dp[i - 1];
        Dp[i] %= MOD;
    }
    Dp[0] = 0;
    while(T--) {
        int A, B;
        long long Ans;
        scanf("%d %d", &A, &B);
        Ans = Dp[B] - Dp[A - 1];
        if(Ans < 0) {
            Ans += MOD;
        }
        Ans %= MOD;
        printf("%I64d\n", Ans);
    }
    return 0;
}
