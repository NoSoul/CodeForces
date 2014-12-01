#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a < *(int *)b ? 1 : -1;
}

int main()
{
    int i, j, K, sum;
    int A[12];
    scanf("%d", &K);
    for(i = 0; i < 12; ++i)
    {
        scanf("%d", &A[i]);
    }
    if(K == 0)
    {
        printf("0\n");
    }
    else
    {
        qsort(A, 12, sizeof(int), cmp);
        for(j = 1, sum = i = 0; i < 12; ++i, ++j)
        {
            sum += A[i];
            if(sum >= K)
            {
                break;
            }
        }
        if(sum < K)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", j);
        }
    }
    return 0;
}
