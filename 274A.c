#include <stdio.h>
#include <stdlib.h>

#define MAXN    100000

int A[MAXN];
char Visit[MAXN];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int Find(int key, int N)
{
    int Left, Right, Mid;
    Left = 0;
    Right = N - 1;
    while(Left <= Right)
    {
        Mid = (Left + Right) >> 1;
        if(A[Mid] == key)
        {
            return Mid;
        }
        else if(A[Mid] > key)
        {
            Right = Mid - 1;
        }
        else
        {
            Left = Mid + 1;
        }
    }
    return -1;
}

int main()
{
    int N, K, i, Ans, Cnt, Num, pos;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    if(K == 1)
    {
        printf("%d\n", N);
        return 0;
    }
    qsort(A, N, sizeof(int), cmp);
    Ans = 0;
    for(i = 0; i < N; ++i)
    {
        if(!Visit[i])
        {
            Cnt = 0;
            Num = A[i];
            pos = i;
            do
            {
                ++Cnt;
                Visit[pos] = 1;
                if(Num <= 1e9 / K + 1)
                {
                    Num *= K;
                    pos = Find(Num, N);
                }
                else
                {
                    pos = -1;
                }
            }
            while(pos != -1);
            Ans += (Cnt + 1) / 2;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
