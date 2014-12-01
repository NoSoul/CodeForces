#include <stdio.h>
#include <stdlib.h>

int A[100000];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, i, Sum;
    scanf("%d", &N);
    for(Sum = i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
        Sum += A[i];
    }
    if(Sum == N)
    {
        A[0] = 2;
    }
    qsort(A, N, sizeof(int), cmp);
    if(Sum == N)
    {
        for(i = 0; i < N; ++i)
        {
            printf("%d ", A[i]);
        }
    }
    else
    {
        printf("1 ");
        for(i = 0; i < N - 1; ++i)
        {
            printf("%d ", A[i]);
        }
    }
    return 0;
}
