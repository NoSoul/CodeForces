#include <stdio.h>

typedef struct
{
    int d, h;
} Node_t;
Node_t A[100001];

int main()
{
    int N, M, i;
    int Ans = 0;
    scanf("%d %d", &N, &M);
    for(i = 0; i < M; ++i)
    {
        scanf("%d %d", &A[i].d, &A[i].h);
        if(A[i].h > Ans)
        {
            Ans = A[i].h;
        }
    }
    if(A[0].d != 1)
    {
        if(A[0].h + A[0].d - 1 > Ans)
        {
            Ans = A[0].h + A[0].d - 1;
        }
    }
    for(i = 1; i < M; ++i)
    {
        if(A[i].h > A[i - 1].h + A[i].d - A[i - 1].d || A[i].h < A[i - 1].h - A[i].d + A[i - 1].d)
        {
            puts("IMPOSSIBLE");
            return 0;
        }
        else
        {
            if(A[i - 1].h <= A[i].h)
            {
                int max = A[i - 1].h + A[i].d - A[i - 1].d;
                if(A[i].h + (max - A[i].h) / 2 > Ans)
                {
                    Ans = A[i].h + (max - A[i].h) / 2;
                }
            }
            else
            {
                int max = A[i].h + A[i].d - A[i - 1].d;
                if(A[i - 1].h + (max - A[i - 1].h) / 2 > Ans)
                {
                    Ans = A[i - 1].h + (max - A[i - 1].h) / 2;
                }
            }
        }
    }
    if(A[M - 1].d != N)
    {
        if(Ans < A[M - 1].h + N - A[M - 1].d)
        {
            Ans = A[M - 1].h + N - A[M - 1].d;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
