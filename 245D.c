#include <stdio.h>

int main()
{
    int i,j,k,N;
    int B[101][101];
    scanf("%d",&N);
    for(i=1; i<=N; ++i)
    {
        for(j=1; j<=N; ++j)
        {
            scanf("%d",&B[i][j]);
        }
    }
    for(i=1; i<=N; ++i)
    {
        for(k=0,j=1; j<=N; ++j)
        {
            if(i!=j)
            {
                k|=B[i][j];
            }
        }
        printf("%d ",k);
    }
    return 0;
}
