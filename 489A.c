#include <stdio.h>

int main()
{
    int N, i, j, k, Cnt;
    int A[3000];
    int Ans[3000][2];
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(Cnt = i = 0; i < N - 1; ++i)
    {
        int k = i;
        for(j = i + 1; j < N; ++j)
        {
            if(A[j] < A[k])
            {
                k = j;
            }
        }
        if(k != i)
        {
            Ans[Cnt][0] = i;
            Ans[Cnt][1] = k;
            ++Cnt;
            A[k] ^= A[i];
            A[i] ^= A[k];
            A[k] ^= A[i];
        }
    }
    printf("%d\n", Cnt);
    for(i = 0; i < Cnt; ++i)
    {
        printf("%d %d\n", Ans[i][0], Ans[i][1]);
    }
    return 0;
}
