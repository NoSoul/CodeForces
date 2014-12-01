#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, D, M, i, Sum;
    int A[100];
    scanf("%d %d", &N, &D);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    qsort(A, N, sizeof(int), cmp);
    for(Sum = i = 0; i < N && i < M; ++i)
    {
        Sum += A[i];
    }
    if(M > N)
    {
        Sum -= (M - N) * D;
    }
    printf("%d\n", Sum);
    return 0;
}
