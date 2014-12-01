#include <stdio.h>

typedef long long LL;

LL GetSum(LL i, LL K)
{
    return (i + K) * (K - i + 1) / 2;
}

LL Binary(LL K, LL N)
{
    LL Left = 1, Right = K, Mid;
    while(Right > Left)
    {
        Mid = (Left + Right) / 2;
        if(GetSum(Mid, K) == N)
        {
            return Mid;
        }
        else if(GetSum(Mid, K) < N)
        {
            Right = Mid;
        }
        else
        {
            Left = Mid + 1;
        }
    }
    return Left;
}

int main()
{
    freopen("IO", "r", stdin);
    LL N, K, index;
    while(scanf("%lld %lld", &N, &K) != EOF)
    {
        if(N == 1)
        {
            puts("0");
            continue;
        }
        if(N <= K)
        {
            puts("1");
            continue;
        }
        --N;
        if(N == 0 || N > K * (K - 1) / 2)
        {
            puts("-1");
            continue;
        }
        index = Binary(K - 1, N);
        if(GetSum(index, K - 1) == N)
        {
            printf("%d\n", K - index);
        }
        else
        {
            printf("%d\n", K - index + 1);
        }
    }
    return 0;
}
