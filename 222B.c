#include <stdio.h>

int A[1001][1001];
int R[1001],C[1001];

int main()
{
    int N,M,K,i,j,x,y,temp;
    char ch;
    scanf("%d %d %d",&N,&M,&K);
    for(i=1; i<=N; ++i)
    {
        for(j=1; j<=M; ++j)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=1; i<=N; ++i)
    {
        R[i]=i;
    }
    for(j=1; j<=M; ++j)
    {
        C[j]=j;
    }
    while(K--)
    {
        scanf("%*c%c %d %d",&ch,&x,&y);
        if(ch=='g')
        {
            printf("%d\n",A[R[x]][C[y]]);
        }
        else if(ch=='c')
        {
            temp=C[x];
            C[x]=C[y];
            C[y]=temp;
        }
        else
        {
            temp=R[x];
            R[x]=R[y];
            R[y]=temp;
        }
    }
    return 0;
}
