#include <stdio.h>

int main()
{
    int i,j,N,M;
    scanf("%d",&N);
    M=N*N;
    for(i=1; i<=N*N/2;)
    {
        for(j=0; j<N/2; ++j,++i,--M)
        {
            printf("%d %d ",i,M);
        }
        printf("\n");
    }
    return 0;
}
