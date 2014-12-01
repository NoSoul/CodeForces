#include <stdio.h>

int Fun(int *data, int i, int j, int K)
{
    if(j < i)
    {
        return data[i] - (i - j) * K;
    }
    else
    {
        return data[i] + (j - i) * K;
    }
}

int main()
{
    int N, K, i, j, Min, Minid;
    int A[1000];
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    Min = 0x7fffffff;
    for(i = 0; i < N; ++i)
    {
        int Cnt = 0;
        for(j = 0; j < N; ++j)
        {
            if(i == j)
            {
                continue;
            }
            if(A[j] != Fun(A, i , j, K))
            {
                ++Cnt;
                if(Fun(A, i, j, K) <= 0)
                {
                    Cnt += 2 * N;
                    break;
                }
            }
        }
        if(Cnt < Min)
        {
            Min = Cnt;
            Minid = i;
        }
    }
    printf("%d\n", Min);
    for(i = 0; i < N; ++i)
    {
        int dst = Fun(A, Minid, i, K);
        if(A[i] > dst)
        {
            printf("- %d %d\n", i + 1, A[i] - dst);
        }
        else if(A[i] < dst)
        {
            printf("+ %d %d\n", i + 1, dst - A[i]);
        }
    }
    return 0;
}
