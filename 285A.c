#include <stdio.h>

int main()
{
    int n,k,i;
    scanf("%d %d",&n,&k);
    for(i=1; i<=n-k-1; ++i)
    {
        printf("%d ",i);
    }
    for(i=n; i>n-k-1; --i)
    {
        printf("%d ",i);
    }
    return 0;
}
