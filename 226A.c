#include <stdio.h>

typedef __int64 LL;

LL F(LL A, LL N, LL M)
{
    int ret = 1;
    while(N) {
        if(N & 1) {
            ret = (ret % M * A % M) % M;
        }
        A = (A * A) % M;
        N >>= 1;
    }
    return ret;
}

int main()
{
    LL N, M;
    scanf("%I64d %I64d", &N, &M);
    printf("%I64d\n", (F(3, N, M) + M - 1) % M);
    return 0;
}
