#include <stdio.h>

#define MAX 101

char Hash[MAX];

int main()
{
    int N,i,j;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&j);
        ++Hash[j];
    }
    for(j=0,i=1; i<MAX; ++i)
    {
        j+=Hash[i]/2;
    }
    printf("%d\n",j/2);
    return 0;
}
