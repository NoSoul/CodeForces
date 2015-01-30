#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int a;
} Node_t;
Node_t A[100];

int cmp(const void *a, const void *b)
{
    return (*(Node_t *)a).a - (*(Node_t *)b).a;
}

int main()
{
    int N, K, Sum, i, Cnt;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i].a);
        A[i].id = i + 1;
    }
    qsort(A, N, sizeof(Node_t), cmp);
    Sum = Cnt = 0;
    for(i = 0; i < N; ++i)
    {
        if(Sum + A[i].a > K)
        {
            break;
        }
        ++Cnt;
        Sum += A[i].a;
    }
    printf("%d\n", Cnt);
    for(i = 0; i < Cnt; ++i)
    {
        printf("%d ", A[i].id);
    }
    return 0;
}
