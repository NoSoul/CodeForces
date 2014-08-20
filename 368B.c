#include <stdio.h>

#define MAXN	100001

int A[MAXN];
char Flag[MAXN];
int B[MAXN];

int main()
{
    int N,M,i;
    scanf("%d %d",&N,&M);
    for(i=1; i<=N; ++i)
    {
        scanf("%d",&A[i]);
    }
    Flag[A[N]]=1;
    B[N]=1;
    for(i=N-1; i>0; --i)
    {
        if(!Flag[A[i]])
        {
            Flag[A[i]]=1;
            B[i]=1;
        }
        B[i]+=B[i+1];
    }
    while(M--)
    {
        scanf("%d",&i);
        printf("%d\n",B[i]);
    }
    return 0;
}
