#include <stdio.h>

int W[171][171];
double A[171][171], B[171][171];

int main()
{
    int i, j, N;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            scanf("%d", &W[i][j]);
        }
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            if(i == j)
            {
                A[i][i] = W[i][i];
                B[i][i] = 0;
                continue;
            }
            A[i][j] = (1.0 * (W[i][j] + W[j][i])) / 2;
            B[i][j] = 1.0 * W[i][j] - A[i][j];
        }
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            printf("%f ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
