#include <stdio.h>
#include <math.h>

typedef __int64 LL;

int Judge(int num)
{
    int i,j;
    if(num==2)
    {
        return 1;
    }
    if(num==1||num%2==0)
    {
        return 0;
    }
    j=sqrt(1.0*num);
    for(i=3; i<=j; i+=2)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int N,r;
    LL Num;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%I64d",&Num);
        r=sqrt(1.0*Num);
        if((LL)r*r==Num&&Judge(r))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
