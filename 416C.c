#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idx;
    int c, p;
} Request_t;
Request_t R[1000];
typedef struct
{
    int idx;
    int r;
} Table_t;
Table_t T[1000];
char Flag[1000];

int cmp_Request(const void *a, const void *b)
{
    return (*(Request_t *)b).p - (*(Request_t *)a).p;
}

int cmp_Table(const void *a, const void *b)
{
    return (*(Table_t *)a).r - (*(Table_t *)b).r;
}

int main()
{
    int N, K, M, S, i, j;
    int Ans[1000][2];
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d %d", &R[i].c, &R[i].p);
        R[i].idx = i+1;
    }
    qsort(R, N, sizeof(Request_t), cmp_Request);
    scanf("%d", &K);
    for(i=0; i<K; ++i)
    {
        scanf("%d", &T[i].r);
        T[i].idx = i+1;
    }
    qsort(T, K, sizeof(Table_t), cmp_Table);
    M = S = 0;
    for(i=0; i<N; ++i)
    {
        for(j=0; j<K; ++j)
        {
            if(Flag[j]==0 && T[j].r>=R[i].c)
            {
                Ans[M][0] = R[i].idx;
                Ans[M++][1] = T[j].idx;
                S += R[i].p;
                Flag[j] = 1;
                break;
            }
        }
    }
    printf("%d %d\n", M, S);
    for(i=0; i<M; ++i)
    {
        printf("%d %d\n", Ans[i][0], Ans[i][1]);
    }
    return 0;
}
