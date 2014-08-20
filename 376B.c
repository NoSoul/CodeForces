#include <stdio.h>

int A[101];

int main()
{
    int n,m,i,x,y,z,Sum=0;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d %d",&x,&y,&z);
        A[x]+=z;
        A[y]-=z;
    }
    for(i=1; i<=n; ++i)
    {
        if(A[i]>0)
        {
            Sum+=A[i];
        }
    }
    printf("%d\n",Sum);
    return 0;
}
