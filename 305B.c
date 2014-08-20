#include <stdio.h>

typedef long long LL;
LL p,q,temp,Num;

LL GCD(LL a,LL b)
{
    LL temp;
    while(b)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

int main()
{
    int N,i;
    scanf("%I64d %I64d %d",&p,&q,&N);
    temp=GCD(p,q);
    p/=temp;
    q/=temp;
    for(i=1; i<N; ++i)
    {
        scanf("%I64d",&Num);
        temp=GCD(p,Num);
        p=(p/temp-Num/temp*q)*temp;
        temp=GCD(p,q);
        p/=temp;
        q/=temp;
        temp=p;
        p=q;
        q=temp;
    }
    scanf("%I64d",&Num);
    if(q==1&&p==Num)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}
