#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, i, Sum, Max, Ans;
    int A[2000];
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    Ans = 1;
    Max = A[N - 1];
    Sum = 0;
    for(i = 0; i < N - 1; ++i)
    {
        if(Sum + A[i] > Max)
        {
            break;
        }
        ++Ans;
        Sum += A[i];
    }
    printf("%d\n", Ans);
    return 0;
}
