#include <stdio.h>
#include <stdlib.h>

typedef __int64 LL_t;
int A[300001];

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int N, i;
    LL_t Sum;
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    if(N == 1)
    {
        printf("%d\n", A[0]);
        return 0;
    }
    Sum = (LL_t)A[0]*N;
    Sum += (LL_t)A[1]*N;
    for(i=2; i<N; ++i)
    {
        Sum += (LL_t)A[i]*(N-i+1);
    }
    printf("%I64d\n", Sum);
    return 0;
}
