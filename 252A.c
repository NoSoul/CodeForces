#include <stdio.h>

int Ans[101][101];
int A[101];

int main()
{
    int N, i, j, k, Max;
    scanf("%d", &N);
    for(i = 1; i <= N; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(i = 1; i <= N; ++i)
    {
        for(j = i; j <= N; ++j)
        {
            for(k = i; k <= j; ++k)
            {
                Ans[i][j] ^= A[k];
            }
        }
    }
    Max = 0;
    for(i = 1; i <= N; ++i)
    {
        for(j = i; j <= N; ++j)
        {
            if(Ans[i][j] > Max)
            {
                Max = Ans[i][j];
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}
