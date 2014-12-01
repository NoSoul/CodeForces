#include <stdio.h>

int main()
{
    int N, M, i, j;
    scanf("%d", &N);
    M = N / 2;
    for(i = M; i >= 0; --i)
    {
        for(j = 0; j < i; ++j)
        {
            printf("*");
        }
        for(j = 0; j < N - 2 * i; ++j)
        {
            printf("D");
        }
        for(j = 0; j < i; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i = 1; i <= M; ++i)
    {
        for(j = 0; j < i; ++j)
        {
            printf("*");
        }
        for(j = 0; j < N - 2 * i; ++j)
        {
            printf("D");
        }
        for(j = 0; j < i; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
