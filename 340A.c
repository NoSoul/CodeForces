#include <stdio.h>

int GCD(int m,int n)
{
    int r;
    while(n!=0)
    {
        r=n;
        n=m%n;
        m=r;
    }
    return m;
}

int main()
{
    int x,y,a,b,z;
    scanf("%d %d %d %d",&x,&y,&a,&b);
    z=x/GCD(x,y)*y;
    printf("%d\n",b/z-(a-1)/z);
    return 0;
}
