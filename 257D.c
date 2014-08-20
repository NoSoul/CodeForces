#include <stdio.h>

int A[100001];
char Hash[100001];

int main()
{
    int N,i,Sum;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    for(Sum=0,i=N-1; i>=0; --i)
    {
        if(Sum<0)
        {
            Sum+=A[i];
            Hash[i]=0;
        }
        else
        {
            Sum-=A[i];
            Hash[i]=1;
        }
    }
    if(Sum<0)
    {
        for(i=0; i<N; ++i)
        {
            Hash[i]^=1;
        }
    }
    for(i=0; i<N; ++i)
    {
        printf("%c",Hash[i]?'-':'+');
    }
    return 0;
}
