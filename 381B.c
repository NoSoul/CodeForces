#include <stdio.h>

int Hash[5001];

int main()
{
    int M,i,num,max=0,Cnt=0;
    scanf("%d",&M);
    for(i=0; i<M; ++i)
    {
        scanf("%d",&num);
        ++Hash[num];
        if(num>max)
        {
            max=num;
        }
    }
    for(i=1; i<max; ++i)
    {
        if(Hash[i]>=2)
        {
            Cnt+=2;
        }
        else
        {
            Cnt+=Hash[i];
        }
    }
    printf("%d\n",Cnt+1);
    for(i=1; i<max; ++i)
    {
        if(Hash[i])
        {
            printf("%d ",i);
            --Hash[i];
        }
    }
    printf("%d ",max);
    for(i=max-1; i>0; --i)
    {
        if(Hash[i])
        {
            printf("%d ",i);
        }
    }
    return 0;
}
