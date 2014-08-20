#include <stdio.h>

int Min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int N,a,b,c,d,i;
    scanf("%d",&N);
    for(i=1; i<=4; ++i)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(Min(a,b)+Min(c,d)<=N)
        {
            printf("%d %d %d\n",i,Min(a,b),N-Min(a,b));
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
