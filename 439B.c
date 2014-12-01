#include <stdio.h>
#include <stdlib.h>

int A[100000];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, X, i;
    long long Sum = 0;
    scanf("%d %d", &N, &X);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    for(i = 0; i < N; ++i)
    {
        Sum += (long long)X * A[i];
        --X;
        if(X == 0)
        {
            X = 1;
        }
    }
    printf("%I64d\n", Sum);
    return 0;
}
