#include <stdio.h>

int main()
{
    int N,i,s,t,Sum,Res;
    int D[100];
    scanf("%d",&N);
    for(Sum=i=0; i<N; ++i)
    {
        scanf("%d",&D[i]);
        Sum+=D[i];
    }
    scanf("%d %d",&s,&t);
    if(s>t)
    {
        i=s;
        s=t;
        t=i;
    }
    for(Res=0,i=s-1; i<t-1; ++i)
    {
        Res+=D[i];
    }
    Res=(Res>(Sum-Res))?Sum-Res:Res;
    printf("%d\n",Res);
    return 0;
}
