#include <stdio.h>

int Date[12]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
int Hash[466];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,m,d,p,t,i,Max,s;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d %d %d",&m,&d,&p,&t);
        for(s=0,i=1; i<m; ++i)
        {
            s+=Date[i];
        }
        s+=d;
        s+=100;
        for(i=s-t; i<s; ++i)
        {
            Hash[i]+=p;
        }
    }
    for(Max=i=1; i<466; ++i)
    {
        if(Hash[i]&&Max<Hash[i])
        {
            Max=Hash[i];
        }
    }
    printf("%d\n",Max);
    return 0;
}
