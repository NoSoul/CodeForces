#include <stdio.h>

#define MOD	1000000000LL
typedef long long LL_t;

LL_t F[101];

void Init()
{
    int i;
    F[0] = F[1] = 1;
    for(i = 2; i < 101; ++i) {
        F[i] = (F[i - 1] + F[i - 2]) % MOD;
    }
}

int main()
{
    Init();
    int N, M, i, t, x, y;
    int A[101];
    LL_t Sum;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    while(M--) {
        scanf("%d %d %d", &t, &x, &y);
        if(t == 1) {
            A[x] = y;
        } else {
            Sum = 0;
            for(i = x; i <= y; ++i) {
                Sum += A[i] * F[i - x];
                Sum %= MOD;
            }
            printf("%I64d\n", Sum % MOD);
        }
    }
    return 0;
}
