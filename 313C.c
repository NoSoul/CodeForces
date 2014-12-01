#include <stdio.h>
#include <stdlib.h>

typedef long long LL_t;

int Map[2000001];

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int N, M, a, i;
    LL_t Sum;
    scanf("%d", &N);
    Sum = 0;
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &Map[i]);
        Sum += (LL_t)Map[i];
    }
    qsort(Map, N, sizeof(int), cmp);
    M = 4;
    while(N >= M)
    {
        a = N / M;
        for(i = 0; i < a; ++i)
        {
            Sum += (LL_t)Map[i];
        }
        M <<= 2;
    }
    printf("%I64d\n", Sum);
    return 0;
}
