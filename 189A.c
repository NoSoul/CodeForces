#include <stdio.h>

int main()
{
    int n,a,b,c,i,j,k,Max=1;
    scanf("%d %d %d %d",&n,&a,&b,&c);
    for(i=0; a*i<=n; ++i)
    {
        for(j=0; a*i+b*j<=n; ++j)
        {
            k=(n-a*i-b*j)/c;
            if((a*i+b*j+c*k)==n&&(i+j+k)>Max)
            {
                Max=i+j+k;
            }
        }
    }
    printf("%d\n",Max);
    return 0;
}
