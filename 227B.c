#include <stdio.h>

int B[100001][2];

int main()
{
    int N,i,M,Num;
    __int64 Suma,Sumb;
    scanf("%d",&N);
    for(i=1; i<=N; ++i)
    {
        scanf("%d",&Num);
        if(B[Num][0]==0)
        {
            B[Num][0]=i;
        }
        if(B[Num][1]==0)
        {
            B[Num][1]=i;
        }
        else if(B[Num][1]<i)
        {
            B[Num][1]=i;
        }
    }
    scanf("%d",&M);
    Suma=Sumb=0;
    while(M--)
    {
        scanf("%d",&Num);
        Suma+=B[Num][0];
        Sumb+=N-B[Num][1]+1;
    }
    printf("%I64d %I64d\n",Suma,Sumb);
    return 0;
}
