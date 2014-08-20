#include <stdio.h>

int A[101];

int main()
{
    int N,M,i,x,y;
    scanf("%d",&N);
    for(i=1; i<=N; ++i)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&M);
    while(M--)
    {
        scanf("%d %d",&x,&y);
        A[x-1]+=y-1;
        A[x+1]+=A[x]-y;
        A[x]=0;
    }
    for(i=1; i<=N; ++i)
    {
        printf("%d\n",A[i]);
    }
    return 0;
}
