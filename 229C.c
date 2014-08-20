#include <stdio.h>

#define MAXN 1000001

typedef __int64 LL;

int D[MAXN];

int main()
{
    int N,M,A,B,i;
    LL Sum;
    scanf("%d %d",&N,&M);
    while(M--)
    {
        scanf("%d %d",&A,&B);
        ++D[A];
        ++D[B];
    }
    for(Sum=0,i=1; i<=N; ++i)
    {
        Sum+=(LL)D[i]*(N-1-D[i]);
    }
    printf("%I64d\n",(LL)N*(N-1)*(N-2)/6-Sum/2);
    return 0;
}
