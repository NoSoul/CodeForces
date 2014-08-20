#include <stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,M,i;
    scanf("%d %d",&N,&M);
    if(N>=M)
    {
        for(i=0; i<M; ++i)
        {
            printf("BG");
        }
        for(i=0; i<N-M; ++i)
        {
            printf("B");
        }
    }
    else
    {
        for(i=0; i<N; ++i)
        {
            printf("GB");
        }
        for(i=0; i<M-N; ++i)
        {
            printf("G");
        }
    }
    return 0;
}
