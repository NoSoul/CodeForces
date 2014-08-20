#include <stdio.h>

int ModExp(int n,int m,int p)
{
    int k=1;
    n%=p;
    while(m!=1)
    {
        if(m&1)
        {
            k=(k*n)%p;
        }
        n=(n*n)%p;
        m>>=1;

    }
    return (n*k)%p;
}

int Judge(int x,int p)
{
    int i;
    if(ModExp(x,p-1,p)!=1)
    {
        return 0;
    }
    for(i=1; i<=p-2; ++i)
    {
        if(ModExp(x,i,p)==1)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int P,x,Sum;
    scanf("%d",&P);
    for(Sum=0,x=1; x<P; ++x)
    {
        Sum+=Judge(x,P);
    }
    printf("%d\n",Sum);
    return 0;
}
