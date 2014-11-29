#include <stdio.h>

int main()
{
    int T, N, P, M, i, j;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &N, &P);
        M = 2*N+P;
        for(i=1; i<N&&M; ++i)
        {
            for(j=i+1; j<=N&&M; ++j)
            {
                printf("%d %d\n", i, j);
                --M;
            }
        }
    }
    return 0;
}
