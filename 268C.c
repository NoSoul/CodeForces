#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    if(N > M)
    {
        N = M;
    }
    printf("%d\n", N + 1);
    for(M = 0; M <= N; ++M)
    {
        printf("%d %d\n", M, N - M);
    }
    return 0;
}

