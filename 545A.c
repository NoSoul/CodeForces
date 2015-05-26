#include <stdio.h>

int main()
{
    int Mat[100][100];
    int i, j, N, Cnt;
    int Ans[100];
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            scanf("%d", &Mat[i][j]);
        }
    }
    Cnt = 0;
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            if(i != j && Mat[i][j] & 1)
            {
                break;
            }
        }
        if(j == N)
        {
            for(j = 0; j < N; ++j)
            {
                if(Mat[j][i] > 1)
                {
                    break;
                }
            }
            if(j == N)
            {
                Ans[Cnt++] = i + 1;
            }
        }
    }
    printf("%d\n", Cnt);
    for(i = 0; i < Cnt; ++i)
    {
        printf("%d ", Ans[i]);
    }
    printf("\n");
    return 0;
}
