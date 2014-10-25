#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN    200000

typedef struct
{
    int value;
    int pos;
} Node_t;
int A[MAXN];
int B[MAXN];
Node_t C[MAXN];

void Cal(int N, int K)
{
    int i;
    memset(B, 0, sizeof(B));
    for(i=0; i<K&&i<N; ++i)
    {
        B[0] += A[i];
    }
    for(i=1; i<N; ++i)
    {
        B[i] = B[i-1] - A[i-1];
        if(i+K-1 < N)
        {
            B[i] += A[i+K-1];
        }
    }
}

int cmp(const void *a, const void *b)
{
    if((*(Node_t *)a).value == (*(Node_t *)b).value)
    {
        return (*(Node_t *)a).pos - (*(Node_t *)b).pos;
    }
    return (*(Node_t *)b).value - (*(Node_t *)a).value;
}

int main()
{
    int N, K, i, j, Ans, Cur, p;
    scanf("%d %d", &N, &K);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &A[i]);
    }
    Ans = 0;
    Cal(N, K);
    for(i=K; i<N; ++i)
    {
        C[i-K].pos = i;
        C[i-K].value = B[i];
    }
    if(N-K > 0)
    {
        qsort(C, N-K, sizeof(Node_t), cmp);
    }
    p = 0;
    for(i=0; i<N; ++i)
    {
        while(p<N-K && C[p].pos<i+K)
        {
            ++p;
        }
        if(p < N-K)
        {
            Cur = C[p].value + B[i];
        }
        else
        {
            Cur = B[i];
        }
        if(Cur > Ans)
        {
            Ans = Cur;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
