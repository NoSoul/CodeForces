#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int dis;
    int k;
} Node_t;
Node_t A[1000];

int cmp(const void *a, const void *b)
{
    return (*(Node_t*)a).dis - (*(Node_t*)b).dis;
}

int main()
{
    int N, S, i;
    scanf("%d %d", &N, &S);
    for(i = 0; i < N; ++i)
    {
        int x, y;
        scanf("%d %d %d", &x, &y, &A[i].k);
        A[i].dis = x * x + y * y;
    }
    qsort(A, N, sizeof(Node_t), cmp);
    for(i = 0; i < N; ++i)
    {
        S += A[i].k;
        if(S >= 1000000)
        {
            printf("%.6lf\n", sqrt(A[i].dis));
            return 0;
        }
    }
    puts("-1");
    return 0;
}
