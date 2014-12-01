#include <stdio.h>

int main()
{
    int N, M, K, i;
    int R[201];
    scanf("%d %d", &N, &K);
    M = N + N + 1;
    for(i = 0; i < M; ++i)
    {
        scanf("%d", &R[i]);
    }
    for(i = 1; K && i < M; i += 2)
    {
        if((R[i] - 1) > R[i - 1] && (R[i] - 1) > R[i + 1])
        {
            --R[i];
            --K;
        }
    }
    for(i = 0; i < M; ++i)
    {
        printf("%d ", R[i]);
    }
    return 0;
}
