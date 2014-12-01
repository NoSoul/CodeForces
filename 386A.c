#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id, p;
} Bidders_t;
Bidders_t A[1000];

int cmp(const void *a, const void *b)
{
    return (*(Bidders_t *)b).p - (*(Bidders_t *)a).p;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i].p);
        A[i].id = i + 1;
    }
    qsort(A, N, sizeof(Bidders_t), cmp);
    printf("%d %d\n", A[0].id, A[1].p);
    return 0;
}
