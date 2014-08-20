#include <stdio.h>

#define MAXN	100000

int A[MAXN];
int Flag[MAXN];

int main()
{
    int N,i,Max;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&A[i]);
    }
    if(N<3)
    {
        printf("%d\n",N);
        return 0;
    }
    for(i=2; i<N; ++i)
    {
        if(A[i]==A[i-1]+A[i-2])
        {
            Flag[i]=1;
            if(Flag[i-1])
            {
                Flag[i]+=Flag[i-1];
            }
        }
    }
    for(Max=i=0; i<N; ++i)
    {
        if(Flag[i]>Max)
        {
            Max=Flag[i];
        }
    }
    printf("%d\n",Max+2);
    return 0;
}
