#include <stdio.h>

int D[1001],S[1001];

int main()
{
    int M,K,i,Max,Time,Now;
    while(scanf("%d %d",&M,&K)!=EOF)
    {
        for(i=0; i<M; ++i)
        {
            scanf("%d",&D[i]);
        }
        for(i=0; i<M; ++i)
        {
            scanf("%d",&S[i]);
        }
        Max=Now=Time=0;
        for(i=0; i<M; ++i)
        {
            if(Max<S[i])
            {
                Max=S[i];
            }
            Now+=S[i];
            while(Now<D[i])
            {
                Time+=K;
                Now+=Max;
            }
            Time+=D[i];
            Now-=D[i];
        }
        printf("%d\n",Time);
    }
    return 0;
}
