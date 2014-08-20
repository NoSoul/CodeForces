#include <stdio.h>

int Hash[1001];

int main()
{
    int N,i,j,Max;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&j);
        ++Hash[j];
    }
    for(Max=1,j=0,i=1000; i>0; --i)
    {
        if(Hash[i])
        {
            Max=Max>Hash[i]?Max:Hash[i];
            ++j;
        }
    }
    printf("%d %d\n",Max,j);
    return 0;
}
