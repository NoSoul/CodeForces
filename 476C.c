#include <stdio.h>

typedef __int64 LL_t;

int main()
{
    LL_t A, B, i, Ans;
    LL_t MOD = 1000000007;
    scanf("%I64d %I64d", &A, &B);
    Ans = 0;
    for(i=1; i<=A; ++i)
    {
        LL_t temp = B*(B-1)/2;
        Ans += ((temp%MOD)*((i*B+1)%MOD))%MOD;
        Ans %= MOD;
    }
    printf("%I64d\n", Ans);
    return 0;
}
